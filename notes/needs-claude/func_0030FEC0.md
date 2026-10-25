CLASS structural score=52 (52 words differ, 400 vs 400 bytes)

# func_0030FEC0 (0x30FEC0, 400 bytes, dq_player_ai.cpp?)

## What it does
"s does any item with id == key pass the usability gate":
- if `actor->s16[0x10] != 0` (in-party): `inv = actor->ptr364`; if null return 0;
  loop i = 0..5 over `u16 inv->ids[6]` at +0x62; id must equal key, be in
  (0, 0x2BA); `desc = func_001FFBA0(&D_0042CDB0, id)`; then
  `func_0030FD70(actor, desc) != 0` -> return 1. Return 0 after the loop.
- else branch (not in party): if `list == 0` -> `func_00300CB0(0, &D_003D0870, 0x153)`
  (assert stub) and return 0; loop i < `list[0]` over ids `list[i+1]`, same
  filters, plus `if (check != 0) { if (!(desc->f24 & 1)) continue; }` before FD70.

## State of the art
My best C is left (uncommitted, unlinked) at
`src/SLES_539.74/func_0030FEC0.c` — structs `Actor` (s16 at 0x10, `Inv *` at
0x364), `Inv` (u16 ids[6] at 0x62), `Desc` (flags s32 at 0x24), short-circuit
`if (id == key && id > 0 && id < 0x2BA)` and `check == 0 || (desc->flags & 1) != 0`.

**The generated code is the original's exact instruction multiset — 400 vs 400
bytes, every instruction present. Only the basic-block ORDER differs**: my
loop-increment stubs land right after each loop, the original places BOTH
increment stubs at the very end of the function (after the assert block), and
the original shares one `return 0` stub (0x30FF68) between loop-A's exit and
loop-B's condition-false branch (`b .L0030FF68; nop` at +0x13C).

Original layout: [entry+inv check][bodyA][ret1A stub][condA slti/bnel, b->shared ret0][shared ret0 b+nop, falls into else][beqz list][i=0 b condB][bodyB][ret1B stub falls into condB][condB bnel/b->ret0][assert block][INCB b condB + s2++][INCA b condA + s3++][epilogue]

My layout (for + short-circuit): identical except INCA sits at +0xB0 (before
the else) and the else/init shift up 2 words; everything after condB is the
same relative shape shifted by the INCA displacement.

## What I tried
1. `for` loops + explicit `continue` guards — structural, score 52, 400 vs 400.
2. `for` loops + short-circuit `&&`/`||` single-ifs — same layout, same score.
3. `while` with trailing `i = i + 1;` — WORSE: 408 vs 400, score 67.

## Clue for the fix
Both increments are entered only by forward branch (never fall-through: each
body ends in `b ret1` / cond). CodeWarrior apparently sinks branch-only blocks
past the whole if/else here; my C variants didn't reproduce that. Something
about the loop's source form moves the inc block past the else — maybe the
`return 0` after loop A is not a separate return (shared stub!): loop-A exit,
loop-B exit and the assert all end in the SAME `return 0` (condB's false
branch branches BACKWARDS to 0x30FF68, before the else). So the original may
have ONE `return 0;` at the end of the function with loop-A's exit jumping to
it (forward branch — but it sits before the else...). Try: `if (party) {...}
else {...}` with a single trailing `return 0;` and no early return after loop A.

## Also: clones queued behind it
`func_00310050` (0x310050, 416) and `func_003101F0` (0x3101F0, 416) in
asm/SLES_539.74/game_30FEC0.s are near-clones (same skeleton; key compare via
`andi a1,0xFF` + `lbu 0xF(desc)` / `lw 0x20(desc) & mask` instead of `lhu
0x62`). They will hit the SAME block-layout issue — solve this one and the
other two should fall, and their assert lines are 0x122 and 0xF0.
