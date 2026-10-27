# needs-claude: func_001BCC30

Best attempt CLASS: `CLASS structural score=84 (83 words differ, 508 vs 512 bytes)`
(try_match `-- -O3`; first form — twin's switch+ternary — scored 106 / 496 B).

Size 512 B (0x1BCC30..0x1BCE30). asm/SLES_539.74/game_1BC310.s.
Twin of func_001BCA30 — read notes/needs-claude/func_001BCA30.md first; same
prologue, same `Transform` layout, same store-back tail, helper is
`func_0013B7B0(out@sp+0x40, va@sp+0x30, vb@sp+0x20)` (asmfunc/func_0013B7B0.c).
`func_001BCA30(Transform*, s32 mode)` with the same mode meanings:
mode==6: va from `*(f32*)(t->p0/p1/p2 + 4)` + 1.0f, vb from record `t+0x18`;
mode==9: va from record `t+0x18`, vb from record `t+0x30`; else `return 0`.
Each record slot: `flag ? value.f : (f32)value.i`, slot 3 is constant 1.0f.

## Best C (untracked at src/SLES_539.74/func_001BCC30.c — DELETE it or keep_funcs
## will register it and the link fails; same problem as the BCA30 stub)

Same typedefs as notes/needs-claude/func_001BCA30_best.c (TaggedF/TaggedSlot/
Transform), plus locals `TaggedSlot *s; f32 x;` declared after the arrays, and
each tagged read as its own if/else through the `s` pointer:

```c
    s = t->a;
    if (!s[0].flag) { x = (f32)s[0].value.i; } else { x = s[0].value.f; }
    vb[0] = x;
    ... (same for s[1], s[2]; case 9 reads s = t->a into va, s = t->b into vb)
```
switch + ternary `s[i].flag ? s[i].value.f : (f32)s[i].value.i` scored the same
508 as the if/else; ternary on `t->a[i]` directly scored 496. Store-back tail
plain: `if (t->type == 3) { *(f32 *)(t->p0 + 4) = out[0]; }` etc., `return 1;`.

## What the remaining diff needs (same wall as the twin)
- Tagged slots 1–2 of each block: orig `lw v0,K(s0); bnez v0,skip; addiu a0,s0,K;
  lwc1 f0,4(a0); b join; cvt.s.w (delay); skip: lwc1 f0,4(a0)` — base in `$a0`,
  two separate relative lwc1. Slot 3 reuses `$a0`: `lw v0,0x10(a0); bnel v0,+3;
  lwc1 f0,0x14(a0) (delay); lwc1 f0,0x14(a0); cvt.s.w` (5 words, no addiu —
  mine keeps an extra `b`). Mine: `beqz/b eql` to a warm float path, base `$v1`
  (slot 2 `addiu v1,v1,8` — orig `addiu v1,a0,8`), and one word short overall
  (127 vs 128).
- Case-6 p0/p1/p2 loads: orig `lw $v1,0x4($s0); lwc1 f0,4($v1)` — mine `lw $a0`
  (register-only; permuter territory).
- Store-back: slot 1 `beq; addiu a0,s0,8` delay + stub `lw v0,4(a0); b back;
  swc1 f0,4(v0)` (mine `lw v0,0xC($s0)`, no a0); slot 2 `beq; lwc1 f0,0x48(sp)`
  in the delay slot (mine hoists that lwc1 after the stub, giving the extra
  word); slot 0 `beql` + `lw v0,4(s0)` stub placed last of the three.
- MH2: read Index + "Branch layout: returns, shared blocks, alignment nops"
  (~2401) and "Delay slots filled or empty" (~2575) — NOT tried yet; the
  "MWCC fills a conditional branch's slot ... never a load/store/call" rule
  suggests the original's `lwc1`-in-delay-slot at slot 3 / store-back slot 2
  needs those loads written so they precede the branch in the source.
- Given the "this = addiu base in delay slot" look, try `.cpp` with inline
  member functions on TaggedSlot (idiom "Field load CSE'd where the original
  reloads") — pass `this = &t->a[i]` per slot; and match both twins together.

## Tried (this session, factory-1, 2026-10-27, ~9 tries / 30 min)
1. twin switch + `t->a[i].flag ? :` ternary → 106 / 496 B (loads CSE'd to one
   absolute lwc1, beql, no addiu).
2. `TaggedSlot *s = t->a;` + ternary on `s[i]` → 84 / 508 B (addiu base appears).
3. explicit if/else through `s[i]`, shared `f32 x` local → 84 / 508 B.
4. negated `if (!s[i].flag) {int} else {float}` → 84 / 508 B (no change; CW
   picks the same layout).
