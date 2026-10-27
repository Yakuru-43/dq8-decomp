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
