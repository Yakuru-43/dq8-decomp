# needs-claude: func_001BCA30

Best attempt CLASS: `CLASS structural score=106 (102 words differ, 496 vs 512 bytes)`
(try_match `-- -O3`, ver 3.0.1b151-050317; earlier if/else-if form scored 121 / 484 B).

Size 512 B (0x1BCA30..0x1BCC30). asm/SLES_539.74/game_1BC310.s.

## What it does
`func_001BCA30(Transform *t, s32 mode)`: builds two `f32[4]` vectors on the stack
(sp+0x30 = a1 arg, sp+0x20 = a2 arg), calls `func_0013B7D0(out@sp+0x40, va, vb)`
(asm quat/matrix helper, see src/SLES_539.74/asmfunc/func_0013B7D0.c), then writes
out[0..2] back through `t->p0/p1/p2` when `t->type/flag0/flag1 == 3`.
mode==6: va from `*(f32*)(t->p0/p1/p2 + 4)` + 1.0f; vb from record `t+0x18`.
mode==9: va from record `t+0x18`, vb from record `t+0x30`; else `return 0`.
Each record slot: `flag ? value.f : (f32)value.i` (shared lwc1 + cvt.s.w), flag at
K, value word at K+4, K = 0, 8, 0x10; slot 3 is constant 1.0f (lui 0x3F80 + sw).

## Best C
notes/needs-claude/func_001BCA30_best.c (switch form; struct + TaggedSlot union
layout as in the file). An untracked stub sits at src/SLES_539.74/func_001BCA30.c
(rm not permitted this session) — **delete it**: keep_funcs.py registers it and
the link then fails with `undefined reference to func_001BCA30`. The config
[SLES_539.74.yaml](../../config/SLES_539.74.yaml) line `[0xBCA30, c, ...]` was
removed again for this; don't rebuild with the stub present.

## What the diff needs
- Original per-slot shape: `lw v0,K(base); bnez v0,skip; addiu a0,base,K;
  lwc1 f0,4(a0); b join; cvt.s.w; skip: lwc1 f0,4(a0)` — the base is materialized
  with `addiu` in the delay slot and reused (4(a0), 8(a0), 0xC(v1)); mine uses
  absolute `lwc1 0x1C($s0)` and inverts to `beql` + fallthrough-cvt (1 word/slot
  short; the 3rd slot of each block uses `bnel` with the raw lwc1 in the delay
  slot). Try `.cpp` with inline member accessors (idiom "Field load CSE'd where
  the original reloads") so the base pointer stays live — static helpers did not
  prevent absolute offsets.
- Block layout: original = test9-far / test6 `beql` to body inline / else stub
  `b; daddu v0,0` between test and body; body9 block between body6 and the join
  at BCBA8; store-back: first test `beql` inline, 2nd/3rd `beq` to far stubs
  (each stub `lw v0,...; b back; swc1 4(v0)`). Switch helped (484->496 B);
  permuter was not available to me this session (see 2026-10-27 note
  func_001C9EC0). MH2 index entries I read/tried: switch reverse-order layout,
  loop-with-top-guard (n/a), two-return-0-stub (n/a, it is a return-1 fallthrough).
- Twin: the next function func_001BCC30 (queue row after this one) has the same
  prologue/structure shifted +0x200 — worth matching them together.
