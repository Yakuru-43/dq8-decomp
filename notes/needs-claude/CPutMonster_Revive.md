CLASS structural score=153 (152 words differ, 752 vs 756 bytes)  [-O3, best of 5 attempts, 2026-11-03 factory-3]

# CPutMonster_Revive — 0x355140, size 0x2F4 (768 incl. padding), SLES_539.74

Same slot system as func_00354670 (matched, its src is the working template:
`Slot { s32 type; pad; union {u128 q; struct{f32 x,y,z,w} v;} @0x10; s32 unk20, key, unk28; }`,
stride 0x30, 32 slots). func_00355440 and func_00355820 (this slice) reuse the
clear/shift blocks verbatim — solving one likely solves the others.

## What it does
`CPutMonster_Revive(base, key)`:
- find slot by key (+0x24), -1 if key < 0 or absent;
- `slot = base + idx*0x30`; if `slot->type == 1` return; if `idx < 0` print
  D_003D3930 + return; (type is loaded once, before both tests);
- if `type == 4`: find type-3 slot; if found: k = find-by-key(slots[type3].key)
  (same helper, -1 if key < 0); if k >= 0: clear slot k (type=0,
  unk20/key/unk28=-1, vec.q=0 — in that store order), shift-down loop
  `while (k < 0x1F)` copying type/vec/unk20/key/unk28 of k+1 into k, then
  clear slot 31 via absolute offsets `0x5D0(s1)`/`0x5E0`/`0x5F0..0x5F8`;
  else (no type-3 slot): find type-2 slot, if found set its type = 4;
- join: `slot->type = 1;` then `DebugPrintf(&D_003D3980);` (the store lands in
  the jal delay slot — write the store BEFORE the printf);
- scan all 32 slots, per active (type != 0) `DebugPrintf(&D_003D37F0, i,
  slot->unk20, slot->key)`; then `DebugPrintf(&D_003D37E0);`.

## Best C
notes/needs-claude/CPutMonster_Revive.c.draft. FindSlot355140/FindType355140
static-inlines (copied form from func_00354670.c) match their loops well.

## Status of the diff (attempt 5)
Frame, s1=base (copied in the entry bltz delay slot), s0=scan counter, the
key<0 guard block, idx<0 print, clear blocks, shift loop, join store in the
jal delay slot: all already align. Remaining:
1. **Block order of the type-3 branch.** Orig: after the type-3 scan, the
   miss falls THROUGH into the type-2 scan; the hit branches far with
   `slti $at,a1,0; beqz $at, .L0035528C` to the k path, which sits
   out-of-line AFTER the idx<0 print block. Mine keeps inlining the k path.
   Tried `if (type3 >= 0){k}else{type2}`, `if (type3 < 0){type2}else{k}`,
   `if (0 <= type3){k}else{type2}` — CW still lays k inline.
   The type-2 hit test is `slti $at,a1,0; bnez $at, join` + store inline.
2. **Register numbers**: orig uses a3 for the key-scan counter + idx and a2
   for type; mine lands a2/a1 (one register low). orig keeps the slot pointer
   in v1 across the whole type-4 block (used only in the join delay store);
   mine allocates s0/s2 for it (fix attempt: store-before-printf helped the
   delay slot but not the register).
3. One word short (752 vs 756) after fix 2, likely a lost `nop`/delay word in
   the second FindSlot inline or the active-scan tail.

## Idioms tried
Constant-on-left (`0 <= x` → slti/beqz), arm-order for if/else cold block
(idiom "beqz p falls into the p != 0 arm", idioms.md:828), store-before-call
sinking into the jal delay slot (idioms.md:756), declaration-order for saved
registers (idioms.md:108). Struct/copy form from func_00354670.c +
notes/idioms-new/func_0046B1A0.md (sq-zero clear via union `.q`).
