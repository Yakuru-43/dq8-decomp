---
name: match-function
description: The function factory loop for DQ8. Claim the next function from build/queue.tsv, write C/C++ that compiles to the original bytes, verify, and commit through the gate. Use when tasks/NEXT.md has no open task, or a task says to match functions.
---

# Match one function at a time

Rules from `CLAUDE.md` apply throughout: no contrived C, `#include "common.h"`,
a function counts only when `tools/verify.py` says MATCH and the gate passes.

## The loop
1. **Claim.** Take the first `todo` row in `build/queue.tsv` (it is ordered by
   translation unit, then unblocked first, then smallest). Set it to `claimed`
   with today's date. A `claimed` row older than a day is `todo` again.
2. **Read.** The asm is in `asm/<bin>/*.s` under `glabel func_XXXXXXXX`
   (`grep -l "glabel func_XXXXXXXX" asm/<bin>/`). Note its size, calls, the
   globals it touches, and the struct offsets it uses. Look at its neighbours
   in `src/` (same translation unit): they show types and style.
3. **Draft.** Write `src/<bin>/func_XXXXXXXX.c`, or `.cpp` when an idiom
   below needs C++ (`tools/verify.py` and the build compile `.cpp` as C++;
   wrap the function and its externs in `extern "C" { ... }` so the names
   stay `func_XXXXXXXX`). `0xEND` includes the padding `nop`s after the
   function up to the next 16-byte boundary (objects are 16-aligned; a range
   that stops at the last real instruction shifts every later address and
   the build fails its checksum):
   ```c
   // range: 0xSTART 0xEND
   #include "common.h"

   ...
   ```
   Start from the m2c draft if there is one (`build/repair/<bin>/<func>.c`,
   or `.venv/bin/m2c` on the asm), then clean it: real types, structs from
   `include/game/` headers, no casts the compiler doesn't need.
4. **Compare.** `tools/try_match.py src/<bin>/<func>.c func_XXXXXXXX 0xSTART --show -- -O3`
   (overlays: add `--bin <bin>` before the `--`; the `--` is required)
   prints both disassemblies; `*` marks differing lines. A `*` on a `jal`,
   `lui` or `%lo` line whose only difference is the address (`func_000000`,
   `0x0`) is an unresolved relocation: the real compare masks it, ignore it.
   The last line says `MATCH` or the first real difference. Change the C, not
   the flags (a `// flags:` line needs a reason from a neighbouring file).
5. **Repeat** 3–4. Stop after **30 attempts or 45 minutes**, whichever comes first.
6. **Finisher, only when close:** if the diff is down to register allocation
   or one instruction order, `tools/permute.py func_XXXXXXXX --run 600`.
   Take a permuter result only if it reads like normal C; otherwise use what
   it found as a hint and write it properly. Never paste its output as is.
7. **Verify.** `tools/verify.py src/<bin>/func_XXXXXXXX.c` must print MATCH,
   and `tools/lint_contrived.py` the same file must print nothing.
8. **Record.** Row → `matched`. Batch matches; for each batch:
   `make split && make -j` (six OK), `tools/keep_funcs.py`, stage the `src/`
   files by name, `tools/gate.sh`, commit (`src/` only) when it passes.
   One line per batch in `notes/weekly/<YYYY-Www>.md` with bytes matched.
9. **Stuck** (step 5 limit hit, or only a trick matches): row → `needs-claude`,
   write `notes/needs-claude/func_XXXXXXXX.md`:
   size, what the function seems to do, your best C, the `--show` diff
   (only the differing region if long), what you tried. Don't commit the C.

## Idioms
Patterns that make CodeWarrior emit what the original does. Claude adds one
each time a `needs-claude` function is solved. Check here before step 6.

### Bit-field stores
`lbu` / `andi ~mask` / `or` / `sb` on one byte (read-modify-write of a few
bits) is a C++ bit-field assignment, not hand-written masking:
```c
struct Flags { u8 visible : 1; u8 locked : 1; u8 rest : 6; };
void Obj_SetVisible(Obj *o, s32 on) { o->flags.visible = on; }
```
Writing `p[0x71] = (p[0x71] & ~1) | (on & 1)` by hand gives a different
order or an extra instruction; permuter "fixes" for it (`volatile`, double
stores, `& 0xFFFFFFFFu`) are exactly what the lint refuses.

### Base-class pointer casts
`beqz a0` around `addiu a0, a0, N` (a null check that skips adding an
offset) is a C++ upcast to a base class at offset N in multiple inheritance:
```cpp
Base *AsBase(Derived *d) { return d; }   // d ? (Base *)((char *)d + 4) : 0
```
In C it can only be imitated with a ternary; when the asm has this shape,
the function belongs to the C++ path (step 7 of the roadmap). Until that
exists, mark it `needs-claude` with the note "upcast", don't force it.

### Branch-likely null checks: the value is an integer
`bnel $v0, $zero` with the store in its delay slot, right after a call
(`if (r) r->field = x;`), comes from testing an **integer**. Testing a
pointer of any type gives `beqz` + `nop` instead. Such getters returned an
address as `u32`:
```c
extern u32 func_001AE130(void);          /* returns &D_00411A10 */
u32 work = func_001AE130();
if (work != 0) { *(s32 *)(work + 0x300) = value; }
```
A pointer loaded from memory (`p = *pp; if (!p)`) still gets branch-likely
code, so this applies to call results. Found in P03, `func_00182130`.

### Guard clauses, not nested ifs
`beqz a1, epilogue` then straight-line code with `bltz v0, epilogue` is
early returns. `if (a) { x = f(); if (x >= 0) {...} }` makes CodeWarrior
invert the first branch and duplicate the epilogue jump:
```c
if (key == 0) { return; }
index = func_00298380(obj, key);
if (index < 0) { return; }
obj->slots[index] = 0;
```
Found in P08, `func_0029D750`.

### Saved registers follow declaration order
If the code is right but two locals have swapped `$s0`/`$s1`, swap the order
of their declarations (and assign after declaring, not in the initializer).
In P18 (`func_0029BB90`), `s32 i; s32 *cursor;` gave the original
allocation and `s32 *cursor = ...; s32 i;` gave it swapped.

### Asserts and their strings
`lui/addiu %hi/%lo(D_x)` for a file name, a line number in `$a1`, a second
string, then `jal func_0012D4D8` is a failed `assert(expr)`: file, line,
expression text. Execution continues after it. Until roadmap step 6 lets a
file own its `.rodata`, refer to the strings by symbol, not as literals
(a literal adds `.rodata` and `tools/verify.py` reports `DATA`):
```c
extern char D_003C1FC0[];   /* "mg_draw.cpp" */
extern char D_003C1FD0[];   /* "texman" */
if (texman == NULL) { func_0012D4D8(D_003C1FC0, 104, D_003C1FD0); }
```
Found in P23, `func_00145C30`.

### Inline helpers, and their depth limit
A value computed into a register and then branched on (`sltu`, `xor`/`sltiu`
before a `beqz`) where plain C folds the compare into the branch often comes
from a small inline function returning a condition, e.g.
`inline s32 IsEmpty(Ch *c) { return c->open && c->rd == c->wr; }`. Inline
functions nest only one level: if `IsBusy(id)` calls `GetChannel(id)`, the
inner call stays a `jal`. Pass the pointer instead and let the caller write
`IsBusy(GetChannel(id))`; the original often recomputes the same lookup twice
exactly like that. A `return b ? b != 0 : 0;` from a `u8` function gives the
`beql`/`sltu`/`andi 0xFF` tail. Found in P28, `func_0025B760`.

### A bool compared with `false` (C++)
`sltu`/`slt`/`xori`+`sltiu` into `$v0`, then `beqz`/`bnez`/`beql` on `$v0`,
is a C++ `bool` compared against `false`, a common style in this codebase:
```cpp
if ((record != 0) != false) { return record->id; }   // P02, func_00340E10
inline bool IsLinking(void) { return D_00410044 == 1; }
if (IsLinking() != false) { ok = 0; }                  // P33, func_00195CC0
```
`== true` compares against 1 instead (`li 1` + `bne`), and in C, or with a
plain `if (IsLinking())`, the compare folds into the branch. The file must
be `.cpp`.

### Constant on the left
`slt $at, $s1, $zero` + `bnez $at` (instead of `bltz $s1`) is `if (0 <= x)`;
`x >= 0` gives `bltz`. Found in P33.

### One return stub means nested ifs
Several paths branching to a single `b epilogue; move $v0, $s1` came from one
`return ret;` at the end with the conditions nested above it. Early
`return ret;` statements each get their own stub. Found in P33.

### Struct copies show the member types
A struct assignment copies member by member: a scalar is one `lw`/`sw`, an
array of 4-byte elements is a loop of 8-byte steps, a struct of floats is
`lwc1`/`swc1` per float, and a 16-byte vector type is `lq`/`sq` (a loop of
`lq` pairs for an array). A 16-byte gap before a float group is
`__attribute__((aligned(16)))` on that member (aligning the type itself
switches its copy to `lq`). A vector that copies with `lq` alone and in
arrays: `union Vec { u128 q; struct { f32 x, y, z, w; } v; };` (CodeWarrior
has no anonymous structs). A `adda.s`/`madd.s` pair is plain float math such
as `y += 0.5f * h`. Found in P38, `func_002C60C0`.

### `volatile` on data another thread writes
If a field is loaded twice where C would load it once (`lw $v0` for the test,
`lw $a0` again for the call), and it is a semaphore id, a flag an interrupt
sets, or similar, it was `volatile`. Mark the line `// thread-shared` (the
lint accepts it like `// hw-register`). Never use it to fix a diff on data
only this thread touches. Found in P28, `func_0025B760`.
