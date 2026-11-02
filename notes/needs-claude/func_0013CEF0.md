# func_0013CEF0 — hand-written VU0, not C-expressible

CLASS: n/a — no C attempt made; the function is 100% VU0 microcode (see
below), same call as notes/needs-claude/func_0013B900.md.

**Size:** 0x120 (288 B, 0x13CEF0–0x13D010). Binary SLES_539.74, TU
`game_13BDA0.s`. A byte-exact `asm void` stub already exists at
`src/SLES_539.74/asmfunc/func_0013CEF0.c` (git-ignored, earns no progress).

**What it does:** 4x4 * 4x4 matrix multiply in pure VU0. `a0` = out matrix,
`a1` = matrix A (rows in `$vf1..$vf4`), `a2` = matrix B (columns broadcast:
`$vf5..$vf8` from `0x0/0x10/0x20/0x30(a2)`), `a3` and `t0` = two more
16-vec4 operands (`$vf9..$vf16`) — i.e. a triple product `A*B*C` folded as
two ACC chains (`vmulax`/`vmadday`/`vmaddaz`/`vmaddw` over `$vf20..$vf27`).
Result stored by four `sqc2` to `0x0/0x10/0x20/0x30(a0)`, the last one in the
`jr $ra` delay slot. No prologue, no GPR or FPU instructions at all.

**Why needs-claude:** `lqc2`/`sqc2`/`vmulax`/`vmadday`/`vmaddaz`/`vmaddw`
have no mwccps2 intrinsics; there is no C to write (nothing but VU0 ops and
`jr ra`). Same family as `func_0027DF10`/`func_0027E050` and
`func_0013B900`. Suggested handling: keep the existing asmfunc stub and map
`[0x13CEF0, c, asmfunc/func_0013CEF0]` like the 0x27DFxx family, or leave
the symbol as `asm`.

**Tried:** nothing (correctly skipped per the 0x13B900 precedent note).
