CLASS structural score=90 (89 words differ, 584 vs 580 bytes)   [best attempt, 08:43]

# func_0030EFD0 (592 B, asm/SLES_539.74/game_30EFD0.s, dq_player_ai?)

Collect pass over the actor list at `ai + 0xA8C` into the 32-entry slot table at
`ai + 0xAA4` (stride 0x14, `func_0030F220(ai, i) = ai + i*0x14 + 0xAA4`, already
matched), then two fill-up loops. Best C: `notes/needs-claude/func_0030EFD0_best.c`
(draft kept untracked in `src/` with `// range:` stripped).

Shape:
- `func_0030EFC0(D_004523E0, ai->head)`; memset(ai+0xAA4, 0, 0x280); nSlots(D24)=0;
  nSeen(D28)=0; s3=head(A8C) load between the two memsets; memset(stack counts[6], 0, 0x18);
  bestVal(D34)=0xFFFF in the delay slot of `b` into the bottom-test loop.
- list loop (bottom test `bnel s3,0,body; lw s3,0x18(s3)` + a redundant head `beqz`
  matching a do-while with `node == 0` test AND `while ((node = node->next) != 0)`):
  actor = node+0x1C, break if 0; `func_0035E590(actor) == 1` → `beql` to far block
  (delay `daddu a0,s2` supplies the F240 arg): `func_0030F240(actor)` != 0 and
  `func_00297090(actor) > 0` → flag(D38)=1, `b` into the add path, else continue;
  else `actor->type == 1` (lh 0x10, reg compare with `addiu a0,1`) → continue.
- add path: val = D24 + D28 (loaded BEFORE the 2nd `func_0035E590` call, sum in its
  delay slot); `beql v0,zero →` B-path on the call result. B-path: `func_00297090`
  guard `slt at,zero,v0`+beqz; `if (0 < r)` then `if (!(bestVal < r)) bestVal = r`
  (lw D34 / slt / bnez / sw); `beql s2,v0; sw s1,0xD30` = `if (actor == ai->ref)
  bestIdx = val;` (branch-likely single-store); D24++; `b` back to the shared tail.
  A-path: D28++. Shared tail: `func_0030F220(ai, val)`; store node, actor,
  `(s32)(s16)actor->0xC` (lh then sw), `counts[(s16)actor->0x10]++`.
- post loops: total(D2C) = D24+D28 (store in `b` delay slot); loop 2 `for i=0..total`:
  slot->count = counts[actor->type] (store as jal delay slot), slot->ready(+0x10) =
  (u8)func_0035DBB0(actor, 0, 1); flag=1; loop 3 `for i=nSlots..total`:
  `func_00342850(*(void **)slot->actor)` — ROM: `lw v0,4(v0)`, `jal` with
  `lw a0,0(v0)` in the delay slot — then `sltu v1,zero,v0`/beqz, `lhu 0x24`+`andi 2`+
  `sltu v1,zero,v1`, and `beql v1,zero,exit` with `sw zero,0xD38` in the DELAY SLOT
  (nullified on fallthrough — the single-store-if idiom), `addiu s1,1`, loop test
  `lw D2C/slt/bnel`, and the loop-exit stub `b epi; ld ra,0x40(sp)` between the loop
  and the F240 block.

Tried (3 attempts): 50-slot table (wrong: memset 0x280 / stride 0x14 = 32, everything
after slots was +0x164 off, first diff `addiu a0,s0,0xA0` vs `0xAA4`); `ref` belongs at
0xA94 with a 4-byte gap after `head` (0xA90); `func_0030F240` must be declared `s32`
(s8 gave a caller-side `dsll32/dsra32` extension the ROM lacks); missing `nSeen = 0`
store (sw zero,D28 between the two memsets' arg setup).

Stuck (mine 584 vs 580 B): (a) prologue: ROM order `sw zero,D24 / addiu a0,sp,0x50 /
sw zero,D28 / daddu a1 / lw s3,A8C / jal memset / addiu a2,0x18 / ori v1,0xFFFF /
b / sw v1,D34` — attempt 3's first diff at +0x5C is this region's interleaving
(`ori 0xFFFF` vs my `sw` placement — likely the `node = ai->head` load ordering; a
separate `s32 head` local may be wanted). (b) loop 3 tail: mine became two plain
`beqz` guards (`andi 2; beqz` — no `sltu` normalize, no beql-with-store-in-delay-slot)
and the exit is a two-hop `b` trampoline landing on `sw zero,0xD38`; ROM breaks via
the branch-likely form so the store runs only on the taken path and `i++` follows
inside. `0 < r && (flags & 2) != 0` gave `andi+beqz` instead of `andi+sltu+beql`;
the `!= 0` after `& 2` matched the loop-1 B-path sltu sites but not this one.
permute.py not run (cpp not on PATH in this run, per sessions 61/62/64).
gate/keep_funcs not run (no match).
