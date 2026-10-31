CLASS structural score=27 (26 words differ, 164 vs 168 bytes)  <- best attempt (try 2 of 3, -O3)

# func_001BCF90

- Size: 176 B, 0x001BCF90..0x001BD040 (range end includes the padding; last real
  instruction `jr $ra` at 0x1BD030 + nop delay slot).
- Binary: SLES_539.74, asm in `asm/SLES_539.74/game_1BC310.s`.
- Family: neighbours func_001BC1C0 (matched, tagged rand-scaled store) and the
  func_001B2F00/B2FB0 twins — same "tagged value" idiom: `{s32 tag; f32 val}` pairs
  where tag==0 means the bits are an `s32` (`lwc1` into a scratch + `cvt.s.w`),
  tag!=0 means a raw float.

## What it does

arg0 = three `{s32 tag; char *p}` pairs at +0x00/+0x08/+0x10 (store halves) plus three
`{s32 flag; f32 val}` pairs at +0x18/+0x20/+0x28 (source halves). Body:

1. Convert each tagged val to float (all three up front, before any store):
   flag==0 -> `lwc1 $f0,val; b join; cvt.s.w $fRES,$f0` (cvt in the `b` delay slot),
   flag!=0 -> out-of-line `lwc1 $fRES,val` falling into the join.
   Results: val(+0x1C)->$f2, val(+0x24)->$f1, val(+0x2C)->$f0.
2. Then three sequential guards: `if (tag==3) *(f32 *)(p + 4) = <float>;`
   with the cross-map tag(+0x00)->f2/p(+0x04), tag(+0x08)->f1/p(+0x0C),
   tag(+0x10)->f0/p(+0x14). Then fall through to `b epilogue; addiu $v0,$zero,1`
   and `jr $ra; nop`: **always returns 1**.

Layout details that are hard to get (see diff region below):

- A single base `$a1 = a0 + 0x18` (`addiu $a1,$a0,0x18` in the first `bnez` delay slot)
  serves all six conversion loads: `0/4($a1)`, `8($a1)` for tag[1], but element [1]'s
  **val** goes through a materialized `$v1 = $a1 + 8` (`addiu $v1,$a1,0x8` in the
  block-2 `bnez` delay slot, loads at `4($v1)`); element [2] folds to `0x10/0x14($a1)`.
- The middle store check is a plain `beq` (not `beql`) with `addiu $a1,$a0,0x8` in its
  delay slot and `lw $v0,4($a1)` inside the body; checks 0 and 2 are `beql` with the
  pointer `lw` in the delay slot (`4($a0)`, `0x14($a0)`).
- Each guard body is `b back-to-join; swc1 $fN,4($v0)` in the delay slot; join is
  `b epilogue; addiu $v0,$zero,1`.

## Best C

`notes/needs-claude/func_001BCF90_best.c` (score 27: conversion blocks only; the whole
store section + epilogue is byte-exact with it, incl. all `beql` stubs and return-1).

## Diff region (best attempt)

+0x00 matches (`lw $v0,0x18($a0)`); mine diverges from +0x04: mine `beqz` to an
inline cvt with the raw `lwc1` in a `b` delay slot and base `$v1`; orig `bnez` to
out-of-line raw, cvt fall-through ending `b join; cvt-delay`, base `$a1` (+ the
`$v1=$a1+8` materialization in block 2). Check 1: mine `beql` + `lw 0xC($a0)` delay
slot vs orig `beq` + `addiu $a1,$a0,8` delay + `lw 4($a1)` in body.

## What I tried (3 attempts, -O3, all try_match; ~30 min)

1. Flat struct with `field_00..field_2C`, direct `if (field == 0) cvt else raw` x3 +
   three `*(f32 *)(field_04+4)` stores: score 39 (148 vs 168 B) — CW inverted all
   blocks (bnel + delay-slot raw), no `b`-join, direct 0x18/0x1C-style offsets.
2. (BEST) `S_tv tv[3]` member + `static inline f32 ToFloat(S_tv *)` called
   `ToFloat(tv); ToFloat(tv+1); ToFloat(tv+2)` after `tv = arg0->tv;`: score 27
   (164 vs 168 B). Store section byte-exact. Remaining: conversion block shape
   (mine beqz+delay-raw; orig bnez+cvt-fallthrough+`b`/cvt-delay), `$a1` base
   naming, tag[1] at `8($a1)` vs value via materialized `$v1`.
3. Split into `S_pr pr[3]` + `S_tv tv[3]`, `(pr + 1)->p` / `(tv + 1)->val` spellings
   for element [1]: score 38 — worse; the `(x+1)->` idea made check 1 *more* wrong
   (kept beql) and the store section lost its byte-exactness (stub order shifted).

Float result registers f2/f1/f0 came out right with `f32 v2; f32 v1; f32 v0;`
declaration order in attempts 2-3 (matches the "first declared gets higher reg" idiom).
MH2 Index (rule 8) not consulted — ran out of the session clock.
