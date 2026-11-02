# func_0013BFF0 — mixed C + hand-written VU0 chunks (0x13B900 family)

CLASS structural score=165 (139 words differ, 564 vs 460 bytes) — best C attempt,
see func_0013BFF0_best.c; the VU0 chunks are not C-expressible.

**Size:** 0x1D0 (464 B, 0x13BFF0–0x13C1C0). Binary SLES_539.74, TU
`game_13BDA0.s` — the same TU as the already-needs-claude `func_0013B900` /
`func_0013B970` (pure VU0) and the matched `func_0013C490`.

**What it does:** shortest-path spherical blend of two vec4s.
`void f(Vec4 *out, Vec4 *inA, Vec4 *inB, f32 t)` (a0..a2 + f12):
copies `*inA`→`0x40($sp)`, `*inB`→`0x30($sp)` (`lq`/`sq`, 16-byte opaque
copies); `dot` = VU0 dot product of the two copies (vmul.xyzw + vaddy/vaddz/
vaddw.x + qmfc2.ni→mtc1). If `dot < 0` (c.lt.s): `dot = -dot` and the stack
copy of `*inB` is negated via VU0 (`qmtc2.ni` of -1.0 into vf5x, vmulx, sqc2).
Then `if (dot <= D_003DF410 /* 0.97f */)` (c.le.s, `u8` result via
`andi 0xFF` + beqz — the bool-vs-false idiom shape, computed with sltu-style
`v1` set before the compare):

- taken: `v = a*(1-t) + b*t` (VU0: qmtc2 scalars into vf11x/vf12x, vmulx,
  vmulx, vadd), normalize by VU0 (dot of v with itself, `vsqrt`/`vwaitq`/
  `vaddq.x`, `vnop vnop`, `vdiv $Q, $vf0w, $vf5x`, `vsub` zero, `vwaitq`,
  `vmulq.xyzw`) → `sqc2` to out. Single shared epilogue.
- not taken (nearly parallel, dot > 0.97): `A = func_0012A008();`
  `B = func_00129E60(A); C = func_00129E60((1-t)*A); D = func_00129E60(t*A);`
  `inv = 1.0f/B` (div.s), `out = a*(C*inv) + b*(D*inv)` — FPU muls for the
  scalars, VU0 for the two vmulx + vadd. Note the FPU path recomputes
  `C*inv`/`D*inv` twice (f22 and f0 hold the same product, 13C15C delay slot
  vs 13C168) and the `div.s` result feeds both.

`func_00129E60` is an SDK helper (`sdk_128868.s`, masks its f12 argument,
compares |x| vs 0x3F490FD8≈0.785, calls func_00128868/func_00126468 —
sin-based random). `func_0012A008` is next to it, likely the seed/pick.

**Why needs-claude:** same reason as `func_0013B900` (read that note first):
`lqc2`/`sqc2`/`vmul.xyzw`/`vsqrt`/`vwaitq`/`vdiv`/`qmfc2.ni`/`qmtc2.ni` are
hand-written VU0 macro instructions; mwccps2 has no intrinsics that emit them,
and CodeWarrior statement-level `asm` can't bind the compiler-chosen GPR/FPR
(`$v0` = &sp+0x40, `$a0` = &sp+0x30, scalars via mfc1 $t0) that the chunks
reference. The CPU-side halves (prologue, FPU mul/div, branch shape, the
bool/andi-0xFF test, shared epilogue) are ordinary C. Best C in
`notes/needs-claude/func_0013BFF0_best.c`.

**Tried:** 1 attempt (faithful C of both paths, Vec4 struct copies, guard
returns, helpers as externs) → structural. Not permutable — the VU0 words
never appear. Suggested handling like the 0x27DFxx family: an `asm void`
asmfunc stub (byte-exact, excluded from the metric) or map as `asm`.
MH2 ref not consulted (no FPU-side near miss to fix).
