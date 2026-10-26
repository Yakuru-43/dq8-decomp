# needs-claude: func_0013BDA0

CLASS structural score=72 (70 words differ, 296 vs 304 bytes) — best attempt; see
"REFERENCE MISMATCH" below before trusting any diff.

- asm: `asm/SLES_539.74/game_13BDA0.s`, range 0x13BDA0–0x13BED0 (304 B)
- Signature (decoded): `f32 func_0013BDA0(s32 mode, f32 a, f32 b, f32 c)` —
  $a0=mode, f12/f13/f14 = a/b/c, result in $f0 (several paths `return b` verbatim).

- What it does (from the .s): d = b − a wrapped to (−π, π]:
  `if (!(d <= π)) d -= 2π;` `if (d <= −π) d += 2π;`  (D_003DF4B4=π, D_003DF554=2π,
  D_003DF560=−π, D_003DF564=2π — values in asm/SLES_539.74/data/ctors.data.s).
  Then by mode:
  - mode 0: r = |d| via `if (d < 0) r = -d; else r = d;` (c.lt + b/delay neg + mov);
    if (r < c) return b;
    if (d < 0) { if (c < d) return b; t -= c; }   // sub.s f1,f1,f14 with t=0 live
    if (!(d < 0)) { if (!(c <= d)) return b; t += c; }   // separate re-test!
  - mode 1: t = d / c
  - else: t stays 0.0f (mtc1 $zero from the top; `add.s f0, f12, f1` = a + 0.0f)
  mode 0/1/else all converge on `r = a + t`, then the final wrap
  `if (!(r <= π)) r -= 2π;` (D_003DF564) `if (r <= −π) r += 2π;` (D_003DF568/E=2π)
  and one `jr $ra` epilogue. `return b` paths = mov.s f0, f13 into jr's delay slot.

- Best C: notes/needs-claude/func_0013BDA0_best.c (compiled; 296 B vs 304, 70 words).
  `(f32)(s32)`-free; no flags needed. Structure follows the asm one-for-one.

- REFERENCE MISMATCH (why this is not just another schedule problem):
  `tools/try_match.py` printed an "original" column that does NOT match
  `asm/SLES_539.74/game_13BDA0.s` at all: .s has lwc1 $f0 / sub.s $f2 / no early
  mtc1 / `bnez $a0` dispatch at 0x13BDDC; try_match's orig showed lwc1 $f1,
  sub.s $f3, an early mtc1 $zero,$f2 at +008, and a `beqz $a0` dispatch at +03C
  with the mode==1 div path laid out first. The `orig` hex words on the DIFF line
  (C7808244 = lwc1 $f0, imm 0x8244) DO match the .s comment bytes, so the text
  column and the hex came from different sources. Suspect: this worktree's build/
  tree is stale/foreign for this region (earlier factory sessions left objects),
  or try_match disassembles a different file for 13Bxxx. verify.py (the real gate)
  likely compares against the same stale image — a match obtained here may not be
  trustworthy until `make split && make -j` refreshes the tree (was started at
  16:42, result in the weekly log line).
- Compare: the neighbouring func_0013BCA0's try_match original column DID match
  its .s exactly, so the mismatch is local to this file/region.
- Also see: func_0013BCA0 needs-claude note (same TU, scalar float, sibling).
