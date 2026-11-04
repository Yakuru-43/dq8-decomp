# func_00375910 (SLES_539.74, 352 B, range 0x375910 0x375A70) — decode + best C, 0 attempts made

Session factory-3 2026-11-04 cut at 45 min before the first try_match (context reads
ate the budget). Queue row released to `todo`. Best C: this dir, func_00375910_draft.c.

## Read of the asm (asm/SLES_539.74/game_375910.s)
Frame 0x30; saves ra, s0, f20, f21. `o->f38 = arg1; o->f3C = arg2; o->f3A = 0;` then
`switch (o->f3C)` (one `lb`, tests 0xB,0xA,0x9,0x7,0x5 = reverse source order, cases
5,7,9,10,11 ascending + empty default; cases 9/10 share one block; all arms break).
- case 5: `o->f3A = 0xF;` (0xF materialized in the beql delay slot)
- case 7: `o->f3A = 0xF; o->f10 = 0.5f;` (0.5f via lui/sw, a0=0xF in delay slot)
- case 9/0xA: `o->f3A = 0xF;`
- case 0xB (beql, delay slot `lh $v1,D_003E00A0`):
  ```c
  o->f3A = D_003E00A0 * 5;                       // sll2+addu, sh
  scale = (f32)o->f3A;                            // lh 0x3A reload -> cvt -> f20 (both calls)
  t = D_003DF3D0 / (20.0f * (f32)D_003E00A0);     // lh reload of the global (3 loads total!)
  r = func_00129E60(t * scale);                   // mul in jal delay slot
  v = 1.0f - D_003DF3F4 * r;                      // msub, kept in f21 across call 2
  t = D_003DF3D0 / (20.0f * (f32)D_003E00A0);     // recomputed, fresh lh
  r = func_00129E60(t * scale);
  o->f04 = v;
  o->f08 = 1.0f + D_003DF394 * r;                 // madd
  o->f0C = o->f08;                                // same f0 stored twice, no reload
  ```
  The f21 home is what makes msub sit between the two jal's while the swc1 falls after
  the second: a plain `o->f04 = ...;` before call 2 would co-locate them, so the draft
  keeps `v` as a local and stores after the second call.

## Globals (asm/SLES_539.74/data/ctors.data.s)
D_003DF394 = 0.3f, D_003DF3D0 = 3.141592741f (pi), D_003DF3F4 = 0.2f, D_003E00A0 = s16
(init 1). All gp-relative -> plain externs (<= 8 B, .sdata). `extern f32 func_00129E60(f32);`
(matches src/SLES_539.74/func_001AA760.c — math lib, returns f32).

## KEY FINDING: madd.s / msub.s / adda.s = R5900 MACC, addend is the ACCUMULATOR
Not fd +/- fs*fb! The addend/accumulator is the COP1X ACC register, materialized by
`mtc1 $zero,$fX; adda.s $fX,$fY` (= ACC = 0.0f + fY). Proof: matched
src/SLES_539.74/func_001AA760.c C `v0 = field_C0 + field_D8 * v0` compiles to
`lwc1 f2,C0; lwc1 f3,D8; mtc1 $zero,$f1; nop; adda.s $f1,$f2; madd.s $f0,$f3,$f0`
(C0 appears only via the adda into ACC). So:
- `1.0f - C * r` -> `mtc1 $zero,f3; adda.s f3,f(1.0f); msub.s $f21,fC,f_r` (dead-looking
  f3=0+1.0 pairs in this function's asm are exactly this)
- `1.0f + C * r` -> same with `madd.s`
- dot-product form: `mula.s/madda.s` chain then `madd.s` reads ACC (see game_1AA760.s
  AB358-AB364). The "dead" `mtc1 $zero; adda.s` pairs before other jal args in other
  functions are probably also ACC setups — check before chasing them as dead code.

## Open questions for the next attempt
- f20=scale, f21=v: if swapped, reverse the local declaration order (idioms: saved
  regs follow/reverse declaration order).
- Whether CW really sinks the `o->f04` store past the second jal (draft writes `v`
  local + store after; if that fails, try store before call 2 and compare).
- switch may want the compare-chain form per idioms "Compare chain on constants"
  (tests emitted reverse source order; the asm already shows the chain, no jtbl).
