# needs-claude: func_0023CEE0

CLASS structural score=38 (35 words differ, 232 vs 244 bytes) — best attempt.

Size 256 (0x23CEE0..0x23CFE0), SLES_539.74, file asm/SLES_539.74/game_23C1D0.s.

What it does: `kind != 5 → return 0`; `idx` from `args[0]` (tag==1 → (s32)f, else i);
`slot = (D_003E0B24 && idx < D_003E0B24->count) ? &D_003E0B24->slots[idx] : 0`;
`slot == 0 → return 0`; then four independent blocks k=1..4:
`if (args[k].tag == 3) *(f32 *)(args[k].value.i + 4) = slot->f(0x30+4*(k-1));`
and `return 1`. Same Arg/SlotList family as func_0023B820/B910/BDE0/BEB0 (all matched).

Best C: src/SLES_539.74/func_0023CEE0.c (4 ifs; variants: with `v` local, without,
with `Arg *ap = &args[k]` used for the store).

Diff, original vs mine (after the slot=beql block):
```
orig: lw $v1,0x8($a0); lwc1 $f0,0x30($a2); addiu $v0,3; beq →COLD; addiu $a1,$a0,0x8
mine: lw $v1,0x8($a0); addiu $v0,3; beq →...; lwc1 $f0,0x30($a1)     (slot in $a1!)
```
orig keeps slot in $a2 and materializes &args[k] in $a1 (delay-slot `addiu`) which
the cold store block reads via `lw $v0,0x4($a1); b back; swc1 $f0,0x4($v0)`;
block 4 instead folds: `lw $v0,0x24($a0)`. Mine folds the arg address into `$a0+K`
(`lw $v0,0xC($a0)`) so it is 12 B short and slot lands in $a1. All 4 bodies cold in
orig (after the `return 1` path), inline-ish in mine.

Tried: plain ifs; `v = slot->x` hoisted local; `Arg *ap` local for the store
(both `ap = &args[k]` before the if and inside); tag tested via `args[k].tag`
directly (matches orig `lw $v1,0x8($a0)`). None moved slot to $a2 or kept `ap`.
Not tried: C++ inline helper `PutF(Arg*, f32)` (timebox); tools/permute.py failed
(`FileNotFoundError: cpp` — not on PATH in this worktree).
