# Idioms

Techniques that matched functions the Qwen factory had given up on. The nightly Opus
batch adds one entry per technique (newest last), and every factory session reads this
file before its first attempt and checks the function's asm against the signs.

Entry format:

    ## <short name>
    Sign: what the asm, or Qwen's try_match diff, shows.
    Fix: what to write (C, a type, a compiler flag) and how to try it.
    Example: src/<bin>/<file>.c
    Solved: func_... (date, who)

## divbyzerocheck: a divide guarded by bnez + break 0, 7
Sign: `bnez <divisor>` before `div $zero, a, b` and `break 0, 7` after it, around a `/` or
`%`, and no C rewrite produces the guard (Qwen's notes call it the "div-guard family").
Fix: write the plain `/` or `%`; the guard comes from a compiler flag. Try it with
`tools/try_match.py <file> <func> <vram> --show -- -O3 -flag divbyzerocheck`; on a match
put `// flags: -flag divbyzerocheck` on line 2, under `// range:` (verify.py and the
build read it there).
Example: src/SLES_539.74/func_002FF0D0.c
Solved: func_002FF0D0 func_00301200 func_003012F0 func_00301350 func_00302140
func_0020C5C0 func_00210C90 func_00210F80 func_00212BA0 (2026-10-24, Opus)

## throw(): an unreachable jal func_00101510 + nop spin loop after the body
Sign: `sq $fp` / `addu $fp,$sp` frame, the body, then `b <epilogue>` over a dead block
`jal func_00101510; addiu $a0,$fp,0x20; 5x nop; b -6; nop`, epilogue `addu $sp,$fp`.
Notes call it a "dead C++-EH handler" or "terminate island"; try/catch gets close but adds
`sw $sp,..($fp)` and a bigger frame.
Fix: a C++ file (`.cpp`) whose function has an empty exception specification:
`void f(void) throw() { ...body... }`. CW emits the `__unexpected` handler as that dead
block; `func_00101510` is `__unexpected`. Try `-O4,p` if the `addu $fp,$sp` is not in the
first jal's delay slot (`// flags: -O4,p`). verify.py says `LINK` until
`__unexpected = 0x101510;` is in config/symbol_addrs_SLES_539.74.txt (integration adds it).
Example: notes/needs-claude/func_001007A0.md (Opus attempt section)
Solved: func_001007A0, func_00100880 (byte matches, waiting for the alias; 2026-10-26, Opus)

## Early-return chain: one shift duplicated after a beql, or a matched twin exists
Sign: diff is one extra `srl`/`sra` right after a `beql` whose delay slot already does the
same shift (mine shifts twice, orig once), everything after it +4; or loads like
`lbu $a2,1($a0)` sit in the branch delay slots of the bit tests. Often the note says
"signed/unsigned twin of func_X" and func_X is already in src/.
Fix: copy the twin's C and change only the types. Shape: one local for the tested value
(`u32 b = p[0];`), each case an `if ((b & m) == 0) { *out = ...; return p + n; }` using the
*unshifted* `b` in every expression (`(b >> 2) << 8`, no shared `b >>= 1`), and each
next byte read into a local (`b1 = p[1];`) on the line just above the test that follows.
Example: src/SLES_539.74/func_00100EE0.c (twin of src/SLES_539.74/func_00100F80.c)
Solved: func_00100EE0 (first try from the twin, 2026-10-26, Opus)

## Virtual-base constructor: a dead `daddu s0,a1` + `(s16)` flag test at entry
Sign: entry does `daddu s0,a1,zero; dsll32 v0,s0,16; dsra32 v0,v0,16; bnez v0,..` and
`a1` is never read again (notes call it a "dead save"); the branch target stores
`o+N` to `0(o)` and a vtable to `N(o)`, then jumps back; the common path stores a vtable,
reloads `0(o)` and writes `(o+N) - *(o)` with `subu` to a field of the sub-object.
Fix: a `.cpp` with a real class hierarchy, not hand-written C: `struct D : virtual VB`
with `D::D(args)`. `a1` is CW's hidden most-derived flag. Give D an override of a VB
virtual (that adds the `subu` delta store), and give VB a destructor (`~VB();`, a declaration
is enough). The flag then stays live for the exception cleanup, which is the s0 save.
Pad VB with an `s64` member so the vbase lands 8-aligned. Test with
`try_match.py f.cpp __ct__1DFi <vram>` (the mangled name). verify.py says `LINK` until
`__vt__1D`/`__vt__2VB` (and the ctor name) have aliases in symbol_addrs (integration adds them).
Example: notes/needs-claude/func_00104060.md (Opus attempt section)
Solved: func_00104060, func_00104110 (byte matches, waiting for the aliases; 2026-10-26, Opus)

## Float temporaries swapped: declare locals in reverse, use a struct, pass -O3
Sign: same size and schedule, but two float values sit in each other's registers
(`$f21`/`$f22` saved temps, or `$f4`/`$f5` load pairs with `sub.s` operands flipped).
Fix: first make sure try_match got `-- -O3` (without it the diff is unscheduled, full of
`nop` delay slots, and no use reading). Read arg0 through a struct with named fields
instead of `M2C_FIELD` casts, and keep each call inline in the expression it feeds
(`sx * cosf(a) - sx * s`). If only the callee-saved floats are swapped, swap the order the
locals are declared in: CW gave the local declared *first* the higher register
(`f32 sy; f32 sx;` put sx in `$f21`, sy in `$f22`).
Example: src/SLES_539.74/func_002116B0.c
Solved: func_002116B0 (2 tries, 2026-10-26, Opus)

## Field load CSE'd where the original reloads: go through inline member accessors
Sign: the original reloads a field it already loaded for a guard (`lw v1,8(a0)` again
right after `beql` on `field_08 <= field_04`), and mine reuses the guard's register, so
mine is one `lw` short. Often with a bool kept as `not/sltiu/xori 1` + `beqz`, and the
field's store in that `beqz` delay slot. Typical of MSL streambuf code (Reader view:
eback/gptr/egptr at 0x04/0x08/0x0C, pbase/pptr/epptr 0x10/0x14/0x18, file at 0x1C).
Fix: a `.cpp` with inline member functions on the struct, as the library had:
`u8 *gptr() const { return field_08; }`, `u8 *eback() const`, `void gbump(s32 n) { field_08 += n; }`,
and write the body with them: `if (r->gptr() <= r->eback()) return -1; bool store = !is_eof(c);
r->gbump(-1); if (store) *r->gptr() = c;`. CW does not CSE loads across inlined member calls.
Static inline helpers taking the struct pointer or a `u8 *&` did not do it; only members.
Also: try_match.py defaults to 2.4 and -O2; pass `--ver 3.0.1b151-050317 ... -- -O3 -Isrc`.
Example: src/SLES_539.74/func_00104DF0.cpp
Solved: func_00104DF0 (about 12 tries, 2026-10-26, Opus)

## Constant in a `b` delay slot and a pre-call copy: an if/else, constant branch first
Sign: `bgez $sX` forward over `b <join>; addiu $v0,$zero,1` (the `addiu` looks dead), the
call block placed after it; at the join a `jal` with `daddu $s0,$v0` in its delay slot and a
later `beqz $v0` testing the *new* v0. That copy saves the value from *before* the call, so the
function returns a different variable than the call's result (Qwen read it as `return ret`).
Mine shows `bltz`/`bltzl` with the call inline, or the value kept in an extra `$s2`.
Fix: write the variable as an if/else with the constant branch first:
`if (val < 0) { result = 1; } else { result = f(...); }` (not `result = 1; if (val >= 0) ...`,
and not `>= 0` first: that order gives `bltzl`). Return `result` at the end.
Example: src/SLES_539.74/func_00211050.c
Solved: func_00211050 (3 tries, 2026-10-26, Opus)

## Two `return 0` share one stub: if/else that falls into one trailing `return 0`
Sign: an inner `beql $v0,$zero,<stub>` jumps far forward to a `b <epilogue>; daddu $v0,$zero,$zero`
stub that the other branch falls into (it sits right after that branch's last block), with a
store in the `beql` delay slot. Mine is 2 words longer: a private `bnel`/`b`+`v0=0` pair, because
each branch has its own `return 0;` and CodeWarrior does not merge separate return statements.
Fix: write the branches as `if (c) { ...; if (r) return 1; x = 0; } else { ...; }` and put a
single `return 0;` after the if/else, so the zero path of both arms falls into it. Keep the early
`return 1;`s inside the arms.
Example: src/SLES_539.74/func_0030A180.c
Solved: func_0030A180 (1 try, 2026-10-26, Opus)

## `p + 8` arg set up before the call-result copy: make the base a pointer
Sign: around `jal f(g(), p + 8, ...)` the original copies `daddu $a0,$v0,$zero` first and puts
`addiu $a1,$sX,8` in the jal delay slot; mine has the two swapped (reorder-only, 2 words). The
base (`$sX`) was declared `s32`.
Fix: type the base as a pointer (`char *`, or the struct pointer it really is), both in the struct
field / local and in the callee's prototype. Integer `+ 8` is scheduled before the `$v0` copy,
pointer `+ 8` after it. A named temp for `g()` does not change it.
Example: src/SLES_539.74/func_0030A180.c
Solved: func_0030A180 (1 try, 2026-10-26, Opus)

## Loop with a top guard and the body inline: `if (cond) do { } while (cond);`
Sign: the original tests once before the loop (`slt $at,$zero,$sN; beqz $at,<after>` with
`i = 0` in the delay slot, or `blez $sN,<after>`), then the body falls through in place and
the loop closes with a bottom `bnez`/`bgtz` (plain, not likely). Mine (a `for`/`while`) jumps
to a bottom test (`slt; bnel`), places the body after the following code (often just before
the epilogue) or folds the decrement into a `bgtzl` delay slot. Usually with a `return` inside the loop.
Fix: write the guard and a do-while: `i = 0; if (i < len) { p = buf; do { ...; } while (++i < len); }`
and `if (len > 0) { do { len--; ... } while (len > 0); }`. Swapping if/else or ternary order
does not move the body; the loop form does.
Also: a stack local one slot too high (mine `0x6E`, orig `0x6C`) next to a buffer is a 4-byte
local typed too small: here `func_00130FD0` is memcpy, so the `u16` result is a `u32` copied
into and returned as `(u16)val` (still `lhu`). The lint refuses `(--x->f < 0)` (double-negate
false hit): `if ((x->f -= 1) < 0)` gives the same code; `x->f--; if (x->f < 0)` does not.
Example: src/SLES_539.74/func_00105E30.c
Solved: func_00105E30 (8 tries, 2026-10-26, Opus)

## Indirect call through `$t9`: a C++ virtual call, vptr placed after the data
Sign: the diff is only the register of an indirect call: orig `lw $t9,N($a0); lw $t9,S($t9);
jalr $t9` (or `jr $t9` for a tail call), mine the same with `$v0`. Plain-C function pointers
(struct member, local, `(*fp)()`) always give `$v0`; only a C++ virtual call gives `$t9`.
Fix: a `.cpp`, functions inside `extern "C" { }`, a struct whose data members come first so
the vptr lands at N (`s32 data[N/4];` then the virtuals; with no data before them the vptr is
at 0) and the called method at slot S (first virtual is S=0x8, then +4 each), called as
`obj->method()`. If the function also stores the vtable first (a constructor), `struct C {
data; C(); virtual f(); }; C::C() { f(); }` gives the exact bytes but verify.py says `LINK`
until `__vt__1C` has an alias; to verify now, store the vptr through a twin struct with a
plain `void **vtbl` at N and `= D_<vtable>;`, then make the virtual call. Pass `-- -O3` to
try_match: without it the schedule (e.g. `daddu s0,a0` in the jalr delay slot) looks wrong.
Example: src/SLES_539.74/func_00218740.cpp, src/SLES_539.74/func_001BA940.cpp
Solved: func_00218740 (3 tries, 2026-10-27, Opus)

## Two vptr constants in `$v0`/`$v1` the wrong way round: compute the sub-object pointer first
Sign: a vbase constructor helper (vptr store at +N, `*(o+0)` = second vtable, then
`(o+M) - *(o+0)` stored at `+0x48`); the diff is only that the two `lui/addiu` vtable
addresses use `$v0` and `$v1` the other way round, and no statement order fixes it.
Fix: assign `sub = (char *)obj + M;` as the first statement inside `if (obj != 0)`, before
the vptr store, and use `sub` both in the delta `(u32)sub - h2` and in the later
`if (sub != 0)` sub-object build. Use two separate locals for the two `node->handle` loads.
If a matched twin in the same class family exists, copy it and change only the offsets.
Example: src/SLES_539.74/func_00103600.c, src/SLES_539.74/func_001036A0.c
Solved: func_00103600, func_001036A0 (first try from the twin, 2026-10-27, Opus)

## Register clusters swapped around an `or`/`addu`: write the operands in the other order
Sign: register-only diff, same schedule, whole groups of values swapped between two
registers (`$a1`/`$t1` here, even far up the function), and the commutative instruction
that joins two terms (`or $v1,$a1,$v1`, `addu`) prints the *same* registers on both sides,
but the term that lands in `rs` is the other value (orig: `rs` = the term loaded later).
Fix: swap the operands of `|`/`+` in the C (`(w->nreg << 28) | word | 0x4000` instead of
`word | (w->nreg << 28) | 0x4000`). CW colours the left operand's register first, and
that choice ripples back to every earlier value sharing the register. Check try_match got
`-- -O3` first, or the diff is unscheduled and misleading.
Example: src/SLES_539.74/func_0013F240.c
Solved: func_0013F240 (1st try, 2026-10-27, Opus)

## Two inline tests normalized twice, one shared `andi 0xFF`: `return A() && B() == 0;`
Sign: a `u8`/bool function whose body is an inlined test computed twice; after the first
test a *second* `sltu $v0,$zero,$v0` then `beqz` (no `beql`), after the second test
`xor $v0,$v0,$zero; sltiu $v0,$v0,1`, and both paths meet at one `b` with
`andi $v0,$v0,0xFF` in its delay slot (the false path of the first test carries its own
0 into that `andi`). An `if (A) return ...; return 0;` gives `andi`+`beql` instead.
Fix: one return of a logical AND of the two inline calls, the second compared `== 0`
(`!B()` gives `sltu; xori 1` instead of `xor; sltiu`). Keep the helper `static inline`
returning `s32` (`(w & mask) != 0`), plain C.
Example: src/SLES_539.74/func_00308250.c
Solved: func_00308250 (3rd try, 2026-10-27, Opus)

## Flag set with `daddiu $sN,$zero,1`, tested raw: a C++ `bool` in a `.cpp`
Sign: a found/ready flag in an `s` register, set with `daddiu $sN,$zero,0x1` (often in
the delay slot of a `b` out of a loop) where yours gives `addiu`, and the flag is later
tested with a plain `beql`/`bnel $sN,$zero` (no `andi 0xFF`). `s32`/`u32`/`s64` flags
give `addiu`; `u8` gives the `daddiu` but masks the test with `andi`.
Fix: make the file a `.cpp` (functions inside `extern "C" { }`), declare the flag
`bool`, write `found = false;` / `found = true;` and test `if (found)`. CW knows a bool
is 0/1, so it keeps the `daddiu` store and drops the mask.
Example: src/SLES_539.74/func_00294F40.cpp
Solved: func_00294F40 (1st try, 2026-10-27, Opus), func_00104890 (with the switch entry below),
func_0029B6C0 (`bool ret` for the `daddiu $s1,$zero,1` before `break`), func_001053A0

## `andi $r,$zero,0x1; sll $s,$r,N` in a bitfield RMW: the field is set to **0**, not 1
Sign: a `u8 : 1` read-modify-write `lbu; addiu -mask; and; or; sb` whose inserted value
is `andi $r,$zero,0x1` followed by `sll` by the bit position (one `andi` can feed several
`sll`s). `$zero & 1` is 0, so the bit is being cleared. Writing `= 1` folds to
`daddiu $r,$zero,1<<N`, and no RHS trick keeps the `andi`. A field set to 1 at
bit 0 shows as a plain `daddiu $r,$zero,1` instead.
Fix: write `f.bitN = 0;`. CW lowers a constant-0 bitfield store without folding it, so
you get exactly `andi $zero,1; sll; and; or` (it keeps the `or` with 0 too).
Example: src/SLES_539.74/func_0013FA20.c
Solved: func_0013FA20 (1st try, 2026-10-27, Opus)

## `sw $v0,N($s0); lw $v0,N($s0); sw $v0,N($s0)`: a member setter fed by a member getter
Sign: a field is stored, reloaded and stored again with identical encodings (notes call
it "the triplet" or "reload-and-restore"); `x = x` is lint-forbidden, and a static inline
`set(w, w->field)` in C folds the reload away (mine is 8 B short).
Fix: a `.cpp` (inside `extern "C" { }`) with inline member functions:
`void SetBase(char *b) { base = b; ... }` and `char *Base() const { return base; }`, then
`w->base = expr; w->SetBase(w->Base());`. Both the getter and the setter are needed: with
`w->SetBase(w->base)` the reload is still CSE'd. Same mechanism as "Field load CSE'd where
the original reloads". A non-void function that returns garbage on its early path
(`$v0` never set) is `return n;` with `n` not yet assigned; C++ refuses a bare `return;`.
Also pass try_match `--ver 3.0.1b151-050317 ... -- -O3 -Isrc`, or every delay slot is a `nop`.
Example: src/SLES_539.74/func_0013F330.cpp
Solved: func_0013F330 (3 tries, 2026-10-27, Opus)

## Last arm's else falls straight into `jr $ra`: `{ store; return; }` in that arm
Sign: an if/else whose two arms each end in their own if/else. The original's tail is
`b <join>; nop` / `b <join-1>; sw ..` (first arm's else stub) / `sw ..` falling into `jr $ra`
(the last arm's else stub, no branch). Mine has a `b` in that last stub as well (one word
longer, or the stubs look shifted by 4). Qwen's notes call it "structural" and blame the
register allocation, but first look at how the draft reads its fields: wrong registers
everywhere in an `M2C_FIELD(arg0, char **, N)` draft can come from the casts.
Fix: (1) read the object through a struct with named fields, as the matched siblings do
(that took func_0013F0E0 from score 94 to 5); (2) in the *last* arm only, write the guard
as an early return: `if (n1 <= 0 || n2 <= 0) { w->wp = end; return; }` and then the
stores. Keep the first arm as a plain if/else. An early return in the first arm, a single
store shared after the if/else, or `static inline` helpers for each arm all came out worse.
Example: src/SLES_539.74/func_0013F0E0.c
Solved: func_0013F0E0 (8 tries, 2026-10-27, Opus)

## Compare chain on constants, `b <default>` after it, one case body inline: a `switch`
Sign: a value is tested against a few constants in a row (`addiu $v1,$zero,K;
beql $a0,$v1,<L>` with a one-instruction body such as `addiu $a2,$zero,2` in each delay
slot), then `b <fail>` for the default, then *one* multi-instruction case body inline that
falls into the join. An if/else-if chain gives the same tests but turns the last one into
`bnel` to the failure and moves the long arm far away (after the other out-of-line blocks).
Fix: a `switch` with a `default:`. CW emits the tests in **reverse source order** of the
case labels and lays the bodies out in source order, so read the beql order backwards
(tests 4, 2, 1 → write `case 1:`, `case 2:`, `case 4:`, `default:`). Writing the cases
in test order gives the tests reversed and a bigger function. A value set in a case's delay
slot on both paths of an inner `if` (`beqz ..; addiu $a2,1`) is a plain `whence = 1;`
before that `if`.
Example: src/SLES_539.74/func_00104890.cpp
Solved: func_00104890 (5 tries, 2026-10-27, Opus), func_001053A0 (1st try, its word-seek twin;
a store in the delay slot of `beql $v0,$zero,<success>` is annulled on fall-through, so it
belongs at the top of the success block, not before the test), func_003112C0 (1st try,
2026-10-29, Opus: tests `2` then `1`, `b <return 0>`; each case is `if (call() != K) return 0;`
+ setup + `break;`, and the last case's body goes out of line with a `b` back into the shared
tail; Qwen's if/else-if chain gave the same tests but the wrong block order)

## Small then-block placed cold (after a return stub, `b` back) where the original has it inline
Sign: the original falls through a short `if` body (`bne a0,v1,skip; <body>; skip:`), but
mine branches forward (`beq`) to a copy of the body near the epilogue with a `b` back; often a
`return` stub before it gains a `b` (mine 4 bytes longer). Flipping the test (`!=` with an
empty then, constant on the left) changes nothing. Look at what comes *before* the block:
an early return such as `if (p == 0) return r;` followed by the rest of the function.
Fix: nest the rest under the positive test instead: `if (p != 0) { ...; if (n == 16) {..} ...; }
return r;`. The early return makes CW lay the remaining tail out as a separate region and
move the inner `if` body out of line; the nested form keeps it inline (func_00104FE0 went from
score 29 / 388 B to score 4 / 384 B with only this change).
Related, same function: two pointers sharing `u = base + (n + 1)` (`addiu a0,u,0x23` /
`addiu v1,u,0x24`, where mine derives one from the other with `addiu -1`): bump the count
first, `n++; setg(buf, buf + n - 1, buf + n);`. `buf + (n + 1) - 1` and `&buf[n]` did not.
Example: src/SLES_539.74/func_00104FE0.cpp
Solved: func_00104FE0 (about 25 tries over three sessions, 2026-10-27, Opus), func_00105B70
(its wide twin over 4-byte slots: func_00104FE0's C with `u32 buf_24[16]`, `n == 16` / `n = 1`
and a `u16` store matched on the first try, 2026-10-27, Opus; the `andi 0xFFFF` in the
`beqz gptr` delay slot is `u16 ch = result;` before the nested `if`)

## `bgez r; andi v,r,0xFF` / `beqz v; addiu v,v,-0x100` inline after a call: signed `r % 256`
Sign: straight after a `jal` (often `func_00132D38`, the rand), `bgez $v0, skip` with
`andi $v1,$v0,0xFF` in the delay slot, then `beqz $v1, skip; nop; addiu $v1,$v1,-0x100`,
`skip:` and a compare on `$v1`. Hand-written `v = r & 0xFF; if (r < 0 && v != 0) v -= 0x100;`
(nested or not) comes out `bltz` to an out-of-line copy and is 4-8 bytes longer. The same
shape with `0x1F` / `-0x20` (or any 2^n) is `% 32`.
Fix: it is CW's expansion of a signed modulo by a power of two: write `rand() % 256 < weight`
(`func_00132D38()` returning `s32`). No temporary needed.
Also seen in the same function: a loop index from an `s16`-returning callee re-sign-extended
(`dsll32/dsra32 16`) where the original uses `$v0` directly in a `bgezl`: declare the callee and
the local `s32`. And `sw $v0,0x288($s0)` with `addiu $s0,$s2,0xE0` in the `jal` delay slot,
where mine stores `0x368($s2)`: take `sub = &unit->sub;` and write
`sub->data = f(owner, sub->state);` (both through `sub`; `unit->sub.state` as the argument folds
the pointer away).
Example: src/SLES_539.74/func_0029B6C0.cpp
Solved: func_0029B6C0 (3 tries, 2026-10-27, Opus)

## `bnel $x,$zero,+3; <next>; b <epi>; daddu $v0,$zero,$zero` where the original is `beql $x,$zero,<epi>`
Sign: an early `if (x == 0) return 0;` (often inside a loop, `x` a value just loaded from a
table, e.g. a key/terminator) where the original has `beql $x,$zero,<far>` + `daddu $v0,$zero,$zero`
in the delay slot, but mine inverts it: `bnel $x,$zero,+3` with the next instruction (a call's
`daddu $a0,...`) in the delay slot, then `b <epilogue>; daddu $v0,$zero,$zero` (mine 4 bytes
longer, every later word shifted). Changing the loop form (for/while/goto, test in the condition,
break to a trailing `return 0`) changes nothing.
Fix: the tested value is a **pointer**: type the field/local `void *` (or the struct pointer it is)
and the callee parameter it is passed to. Note the opposite rule for `if (r) r->f = x;` stores
(SKILL.md: integer gives `bnel`+store); for the early-return guard, a pointer gives the `beql`.
Same file: a lookup result `entry` (pointer) tested for `-1` comes out `beql $a0,$zero` +
`addiu $v1,$zero,-1` only as `if (entry != 0) return entry->value; return -1;` (the
`if (entry == 0) return -1;` order gives `bnel`).
Example: src/SLES_539.74/func_003072A0.c (kind lookup = inline twin of func_003062B0)
Solved: func_003072A0 (9 tries, 2026-10-27, Opus), func_001B2F00 (call result `r` typed
`void *`; its twin func_001B2FB0 was already matched: check `src/` for the twin first, 2026-10-29, Opus)

## Unrolled `{type, ptr}` slot stores: keep the entry address with one reused pointer local
Sign: k unrolled `if (e->type == 3) *(f32 *)(e->ptr + 4) = v;` tests over an array of
8-byte `{s32 type; char *ptr;}` slots (script-VM output slots). The original materializes
each entry's address, `addiu $aN,$base,8` (0x10, ...) in the test's branch delay slot, then
loads `lw $v0,4($aN)` in the body; mine folds it to `lw $v0,0xC($base)` and is 8 B short per
slot. Often the last slot *is* folded (`0x1C($base)` directly) in the original too.
Fix: write each slot through one pointer local assigned on the line just before its test:
`sl = slots + 1; if (sl->type == 3) { *(f32 *)(sl->ptr + 4) = v; }`. Write a slot directly
(`slots[3].type`, `n->out[2].type`) where the original folds the offset; slot 0 is the same
either way. For float values from a local array, read each into a named `f32` on the line
before its test (`val1 = vals[1];`) so the `lwc1` lands in the test block, as the original.
For `{tag, bits}` inputs converted up front (`tag == 0 ? (f32)bits : *(f32 *)&bits`), give
the middle element its own local (`q = p + 1;`) and keep `bits` `s32` (`u32` gives the
unsigned-convert expansion). If the node base lands in the wrong register, check the
prototype: func_001DE300 has a second, unused `s32` argument, so the base goes to `$a1`.
A `static inline f32 get(Tagged *t) { if (t->tag == 0) return (f32)t->val.i; return t->val.f; }`
also works when it is passed the pointer local (`t = &arg0[1]; buf[1] = get(t);`); called
with `&arg0[1]` directly the offset folds again. Also: try_match.py defaults to 2.4 -O2.
Example: src/SLES_539.74/func_001DC5D0.c, src/SLES_539.74/func_001DE300.c, src/SLES_539.74/func_001C67B0.c
Solved: func_001DC5D0, func_001DE300 (2026-10-28, Qwen factory-1; checked 2026-10-29, Opus),
func_001C67B0 (5 tries, 2026-10-29, Opus), func_001C5590 (1st try from its twin
func_001C5DD0's C, 2026-10-29, Opus)

## `lb; dsll32 24` / `dsra32 24` around a byte compare in a string scan: an `s8` local
Sign: a loop over a `char *` string with `lb $v0,N(p)` in the test, `dsll32 $v0,$v0,24` in
the branch delay slot and `dsra32 $v0,$v0,24` at the top of the body, before a compare with
a constant (`'-'` = 0x2D); a second byte of the same string is compared with no shifts.
Comparing `*p == '-'` directly (`char *` or `s8 *`) gives no shift pair (mine 12 B short).
Fix: read the tested byte into a plain `s8` local in the loop condition and compare the
neighbour byte through the pointer: `s8 c; while ((c = *s) != 0) { if (c == '-' &&
*(s + 1) == '-') { break; } n++; s++; }`. In the same pair of functions, the null guards
`beql $a0,$zero,<stub>; daddu $v0,$zero,$zero` (stub just before `jr $ra`, `return 1` as
`b` over it) come from one combined `if (arg0 == 0 || arg1 == 0) { return 0; }`; two
separate `if`s give `beqz + nop` and a merged tail (8 B short).
Example: src/SLES_539.74/func_0014CE20.c
Solved: func_0014CE20 (2026-10-28, Qwen factory-1), func_0014A630 (its twin, 1st try from
func_0014CE20's C, 2026-10-29, Opus)

## `bgez r; sra v,r,n` / `addiu v,r,2^n-1; sra v,v,n` (plain `bgez`, not `bgezl`): signed `r / 2^n`
Sign: `bgez $a0, join` with `sra $v0,$a0,n` in the delay slot, then the fall-through
`addiu $v0,$a0,2^n-1; sra $v0,$v0,n`, `join:`. Hand-written
`if (r < 0) q = (r + 63) >> 6; else q = r >> 6;` (either order, or a ternary) gives
`bgezl`/`bltzl` or `slt`+`bnel` (1 word or more off). Often next to the `% 2^n` shape above
(`bgez; andi` / `beqz; addiu -2^n`).
Fix: it is CW's expansion of signed division by a power of two: write `r / 64` on an `s32`.
Round-up-to-64: `if (arg0 % 64 != 0) { arg0 = (arg0 / 64 + 1) * 64; } return arg0;`
Example: src/SLES_539.74/func_0022AB70.c
Solved: func_0022AB70 (1st try, 2026-10-29, Opus; byte-identical twin at 0x00168840)

## `beql`/`bc1tl`/`bc1fl` chains whose delay slots load 0/1 into one register, then a join: an inline helper with `return`s
Sign: a value (a node pointer, a 0/1 flag) set by a chain of tests where each **likely**
branch carries the result in its delay slot (`beql $a1,$zero,J; daddu $a1,$zero,$zero`,
`bc1tl J; addiu $v1,$zero,1`, `bc1fl J; daddu $v1,$zero,$zero`, last arm `b J; <const>`), all
arms meeting at one join that stores/tests the value. Writing it with `if/else` arms assigning
a local gives plain `beqz`+`nop` and `bc1f`+`nop` skips, the arms reordered or duplicated.
Fix: put the chain in a `static inline` helper that returns each value early
(`Node *n = l->cur; if (n == NULL) return NULL; l->cur = n->next; return n->item;`), and
call it as `x = Helper(...)`. For float tests pass the **values** as parameters (`InRange(*val,
n->lo, n->hi)`), not the struct: that fixes the load order and the `$f0/$f1/$f2` allocation.
Branch sense per test: a `bc1t` to the out-of-line arm came from `if (!(hi <= lo)) { inline arm }`;
a final `bc1tl J; 1` then `b J; 0` came from `if (v >= hi) return 0; return 1;` (the
`if (v < hi) return 1; return 0;` order gives `bc1fl; 0`).
Example: src/SLES_539.74/func_001F2670.c
Solved: func_001F2670 (7 tries, 2026-10-29, Opus; twin func_001F2760 still open)

## Two back-to-back loops, the first one's cursor/value/end registers swapped: give the second loop its own pointer
Sign: two consecutive pointer loops (fill/copy) where the second starts where the first
ends; register-only diff confined to the **first** loop, whose cursor/value/end cluster
takes the second loop's registers (mine loop1 `a1/a0/v1`, orig `a0/v1/a1`), and the
original's second-loop cursor is the first loop's END register (`addiu $a1,$s0,END`
reused, no copy). One shared `p` continued across both loops gives the swap.
Fix: a separate local for the second loop, initialised from the same address as the first
loop's end: `p = &s->a[0]; do { ... p++; } while (p < &s->a[4]); q = &s->a[4]; do { ...
q++; } while (q < &s->a[8]);`. CW then reuses the END value as `q`'s start. Bottom-tested
loops with no `b` at entry come from `do { } while`, not `for`/`while`.
Example: src/SLES_539.74/func_00181030.cpp
Solved: func_00181030 (first try, 2026-10-29, Opus)

## Compare chain skips `$a0` (constants and the tested value in `$a1`/`$a2`), bare `jal`s with no `daddu $a0`: those callees take `arg0`
Sign: a dispatcher copies `arg0` to `$s0`, then its compare chain keeps the tested value and
the constants in `$a1`/`$a2`/`$v1` and never touches `$a0`; some arms are `jal f; nop` with no
argument set-up while others do `jal g; daddu $a0,$s0,$zero`. Mine is register-only off: the
chain takes `$a0` (`addiu $a0,$zero,1`, value in `$a1`) because my prototypes for the bare
calls take nothing. `$a0` still holds `arg0` there, so CW passes it with no move.
Fix: give every bare-`jal` callee the `arg0` parameter and pass it (`f(arg0);`), even where
m2c wrote `f()`; the callee's own file often confirms it (func_00296AF0 takes `s32 arg0`).
Also: this draft looked 36 bytes long and "structural" at try_match's default -O2; with
`-- -O3` the plain if/else-if chain was already register-only.
Example: src/SLES_539.74/func_00296BD0.c
Solved: func_00296BD0 (7 tries, 2026-10-29, Opus; mh2 catalogue "A switch value in a2 where yours has a1")

## `subu $v0,$sN,$v0` right after a `jal` whose delay slot is `daddu $sN,$v0,$zero`: two different call results, not a self-difference
Sign: `jal f; lw $a0,..` then `daddu $a0,$sX,$zero; jal g; daddu $sX,$v0,$zero` then
`subu $v0,$sX,$v0; blezl ...`. The note says "sX == v0, always 0, CW folded my version and
dropped the whole block (output much shorter)". Wrong reading: the delay slot runs *before*
`g`, so `$sX` holds `f`'s result and `$v0` after the call is `g`'s. Also seen with it: a
callee defined as `s16` but used with no `dsll32/dsra32` after its `jal` in this TU.
Fix: `gain = f(node->obj) - g(obj, 0);` (the `daddu $a0,$sX` before the delay slot means `obj`
was cached in `$sX` from an earlier compare). Declare the unextended callee `extern s32`.
`blezl $sN; daddu $v0,$zero,0; addiu $v0,$zero,1` at the end is `if (best > 0) return 1;
return 0;` (`return best > 0;` gives `slt`). Node/best registers swapped: reorder the locals'
declarations (here `best` first).
Example: src/SLES_539.74/func_00292F60.c
Solved: func_00292F60 (5 tries, 2026-10-29, Opus; no mh2 entry needed)

## `if (addr != 0) { push }` after early returns goes out of line (`bnez` far + `b` back): make `addr` a pointer
Sign: an `int`-typed address computed as `base + (count << 4)` (later masked `& 0x0FFFFFFF`
via `dsll32/dsrl32 4`) is tested `if (addr != 0)` around a short store block; the original
has `beqz $sN, +N` and the block inline, mine has `bnez $sN` to a cold copy near the epilogue
with a `b` back, and an extra `b` before the `return 1` stub (mine 8 bytes longer). Flipping
the test, an empty then, constant-left, nesting under positive tests, an inline helper: no change.
Fix: type the address as a pointer (`u128 *rec = (u128 *)w->base + w->count;`, index it as
`rec[idx] = 0;`, mask with `(u32)rec & 0x0FFFFFFF`). CW lays out a null-pointer test inline
where it moves an integer `!= 0` test's body cold. The `sll 4; addu` of `rec + (idx << 4)` is
`rec[idx]` on the pointer.
Also, same function: `mtc1 $zero,$f0; c.le.s $f20,$f0; bc1t skip` (orig) vs mine
`c.lt.s $f0,$f20; bc1f` is `if (!(amount <= 0.0f)) call;`, not `0.0f < amount`.
Example: src/SLES_539.74/func_001419A0.c
Solved: func_001419A0 (5 tries, 2026-10-29, Opus; no mh2 entry needed)

## `slt $at,$v0,$zero; beql $at,$zero` on a call result where mine has `bgezl $v0`: write `0 <= r`
Sign: a signed test of a call result against zero. The original computes `slt $at,$v0,$zero`
and branches on `$at` (`beql $at,$zero,<hit>`, `bnez $at`...); mine branches on `$v0` itself
(`bgezl`/`bltz`), one word shorter. `r >= 0`, `!(r < 0)` and a named temp all give `bgezl`.
Fix: put the constant on the left: `if (0 <= f(...))`. CW then lowers it as a general `slt`
into `$at`. (`0 < r` likewise gives `slt $at,$zero,$v0`.)
Also, same function: a flag set to a constant in the delay slot of a `jal`, then zeroed in a
`beql $sN,$zero` delay slot after the call, is `flag = 0xC4; h = f(); if (h == NULL) flag = 0;`
(the assignment written before the call; after it, CW puts the test cold, and `h ? 0xC4 : 0`
gives `movz`). The saved registers and stack slots were in reverse order until the locals were
declared in reverse order (see "Float temporaries swapped").
Example: src/SLES_539.74/func_00302FB0.c
Solved: func_00302FB0 (4 tries, 2026-10-29, Opus; no mh2 entry needed)

## Stack arrays/locals at each other's offsets, frame 0x10 too big: declare them in reverse
Sign: same code, but the `addiu $aN,$sp,X` addresses of two local buffers are swapped (mine
puts the first-declared array lowest) and my frame is bigger by padding (`-0x100` vs `-0xF0`).
Fix: CW stacks locals in **reverse declaration order** (last declared lowest), so declare the
one at the highest offset first: original `key@0x40`, `query@0x90`, `out@0xEC` is
`s32 out; char query[0x5C]; char key[0x50];`. The padding went away with the right order;
no need to change the array types.
Example: src/SLES_539.74/func_003112C0.c
Solved: func_003112C0 (2nd try, 2026-10-29, Opus; no mh2 entry needed)
