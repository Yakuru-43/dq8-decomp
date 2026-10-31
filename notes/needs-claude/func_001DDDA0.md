# needs-claude: func_001DDDA0

Best attempt CLASS: `CLASS structural score=84 (83 words differ, 508 vs 512 bytes)`
(try_match `-- -O3`; the twins' best shape — see below).

Size 512 B (0x1DDDA0..0x1DDFA0). asm/SLES_539.74/game_1DC9C0.s.
Third twin of func_001BCA30 / func_001BCC30 — read notes/needs-claude/func_001BCC30.md
first. Same prologue, same `Transform` layout (type/p0/flag0/p1/flag1/p2 at 0x00..0x14,
TaggedSlot a[3] at 0x18, b[3] at 0x30), same mode dispatch (`case 6`: va from
`*(f32*)(p_i + 4)` + 1.0f, vb from record `a`; `case 9`: va from `a`, vb from `b`;
else `return 0`), same store-back tail (`type/flag0/flag1 == 3` → store `out[i]` at
`p_i + 4`, `return 1`). Only differences: helper is **func_0013B7D0** (not 0x13B7B0)
and the addresses.

## Best C: copied to notes/needs-claude/func_001DDDA0_best.c
Byte-identical in shape to func_001BCC30_best.c with the helper swapped. Locals
`f32 out[4]; f32 va[4]; f32 vb[4];` (out first → out at sp+0x40 ✓), then
`TaggedSlot *s; f32 x;`. src/ draft was DELETED this session (this repo's rule:
no src draft for an unmatched function; `tools/gen_configs.py` would register it
and break the build — see the CAUTION in func_001BCC30.md).

## Diff wall (identical to both twins; their note has the details)
First diff +0x20: mine `lw $a0,0x4($s0)` in the case-6 beql delay slot, orig
`lw $v1,0x4($s0)`. Then the tagged slots (base should walk through `$a0`:
`addiu a0,s0,0x18` in the first bnez delay, `addiu v1,a0,8` for slot 1, slot 2
reuses `$a0` with no addiu — 5 words, mine keeps an extra `b`, one word short),
and the store-back (slot 0 `beql` + `lwc1 f0,0x40(sp)` in its delay slot with the
stub placed last; slot 1 `beq; addiu a0,s0,8` delay + stub `lw v0,4(a0)`; slot 2
`beq; lwc1 f0,0x48(sp)` in the delay slot).

## Tried (this session, factory-1, 2026-10-27, 3 try_match attempts)
1. Own draft: named structs (`Obj`/`Triple`/`Val`), if/else-if chain, ternary
   `tag != 0 ? f : (f32)i` → 496 B, score 120 (wrong stack-slot order: CW gives
   the FIRST-declared array the HIGHEST address; out must be declared first;
   and my `t->tag1` ternarys kept offset addressing on `$v1` instead of walking
   `$a0`).
2. Twins' best shape copied in → 508 B, score 84 (their exact wall).
3. `flag == 0 ? (f32)i : f` ternary everywhere (the "tag==0 ternary" lead left
   in func_001BCC30.md) → 484 B, score 110: WORSE, it drops a `b` block. Keep
   the `if (!s[i].flag) { } else { }` form.

## Leads for the next attempt (untried by any twin session)
- MH2 "Delay slots filled or empty" (line 2575, read this session): MWCC never
  moves a load into a conditional branch's slot from *after* it — yet the orig
  has `lwc1` in the `beql`/`beq` delay slots of the store-back. Write the out[i]
  loads into named locals BEFORE each `if` (`f32 r = out[i]; if (t->type == 3) …`).
  Also the default-first-switch trick (empty/`return 0` default written FIRST)
  empties conditional slots function-wide — untried here.
- `.cpp` with inline member functions on `TaggedSlot` (`this` = addiu base in
  the delay slot, cf. notes/idioms.md "Field load CSE'd where the original
  reloads") — suggested in func_001BCC30.md, still untried by all three twins.
- MH2 "Branch layout: returns, shared blocks, alignment nops" (line 2401) —
  not read yet.
- Match all three twins together; fixing one wall probably fixes the other two.
