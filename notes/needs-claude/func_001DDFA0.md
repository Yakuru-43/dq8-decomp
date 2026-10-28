# needs-claude: func_001DDFA0

Best attempt CLASS: `CLASS structural score=82 (79 words differ, 500 vs 512 bytes)`
(try_match `-- -O3`, default-first switch — see Tried).

Size 512 B (0x1DDFA0..0x1DE1A0). asm/SLES_539.74/game_1DC9C0.s. references: func_0013B7B0.
Fourth twin of func_001BCA30 / func_001BCC30 / func_001DDDA0 — read
notes/needs-claude/func_001DDDA0.md (and func_001BCC30.md) first. Same `Transform`
layout (type/p0/flag0/p1/flag1/p2 at 0x00..0x14, TaggedSlot a[3] at 0x18, b[3] at 0x30),
same dispatch (case 6: va from `*(f32*)(p_i + 4)` + 1.0f, vb from `a`; case 9: va from
`a`, vb from `b`; else `return 0`), same store-back (`type/flag0/flag1 == 3` → store
`out[i]` at `*(p_i) + 4`, `return 1`). Only differences from DDDA0: helper is
**func_0013B7B0** and the addresses. The twins' wall reproduces here EXACTLY
(baseline 84/508 = their score, same first diff).

## Best C: notes/needs-claude/func_001DDFA0_best.c
The DDDA0 best with helper swapped AND `default: return 0;` moved to the TOP of the
switch (score 82/500 — better than the twins' 84/508; default-first had been listed
"untried" in func_001DDDA0.md). src draft deleted (family rule: no src file for an
unmatched function, gen_configs would register it and break the build).

## Diff wall (default-first shape; first diff +0x20)
- Case-6 entry: `lw $v1,0x4($s0)` in the case-6 `beql` delay slot; mine `lw $a0,...`
  (and `$a0` follows through the three va loads — $a0 vs $v1 coloring).
- Tagged slots (both cases): orig walks `$a0`: `lw $v0,off($s0); bnez $v0,<float>;
  addiu $a0,$s0,0x18` (delay), then the INT path inline: `lwc1 $f0,off; b <store>;
  cvt.s.w` (delay), then the FLOAT path LAST: `lwc1 $f0,off($a0)` falling into the
  store. Slot 1: `lw $v0,8($a0); bnez; addiu $v1,$a0,8` delay. Slot 2 reuses `$a0`
  (no addiu): `lw $v0,0x10($a0); bnel $v0,<join>; lwc1 $f0,0x14($a0)` delay, int path
  fall-through. Mine inverts the test (`beqz`, int as taken path) and keeps the base
  in `$v1` for all three slots.
- Store-back as in the twins' note (slot 0 `beql` + `lwc1 $f0,0x40($sp)` delay, stub
  last; slot 1 `beq; addiu $a0,$s0,8`; slot 2 `beq; lwc1 $f0,0x48($sp)` delay).

## Tried (factory-1, 2026-10-28, 4 try_match attempts)
1. Twins' best shape (case 6/9, default last) → 508 B, score 84 (their exact wall).
2. `r0 = out[0];` named locals before the three store-back `if`s (declared after `x`)
   → 508 B, score 87: WORSE (MH2 "pre-branch loads fill delay slots" lead from
   func_001DDDA0.md — dead end here, CW sinks the loads anyway).
3. Default-first switch → 500 B, score 82: best. Keep this shape.
4. (Baseline re-runs for the diff.)

## Leads for the next attempt (still untried by all FOUR twins)
- Positive-test form: `if (s[i].flag != 0) { x = s[i].value.f; } else { x = (f32)s[i].value.i; }`
  — the wall wants the FLOAT path as the taken branch, int path as fall-through;
  func_001BCC30.md only records the `flag == 0 ? (f32)i : f` ternary (110/484, worse).
- `.cpp` with inline member functions on `TaggedSlot` (getter for the float/int value)
  — suggested in func_001BCC30.md, untried everywhere; the `$a0` base walk smells like
  `this` from an inlined accessor (cf. notes/idioms.md "Field load CSE'd where the
  original reloads").
- MH2 "Branch layout: returns, shared blocks, alignment nops" (~line 2401) — still
  unread by every session on this family.
- Fix the whole family together: four 512 B twins share one wall (BCA30, BCC30, DDDA0,
  DDFA0; helpers 0x13B7B0/0x13B7D0).
