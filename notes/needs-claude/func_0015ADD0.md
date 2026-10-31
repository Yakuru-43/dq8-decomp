// CLASS structural score=43 (43 words differ, 212 vs 212 bytes)  [best attempt, 2026-10-31]

# func_0015ADD0 — needs Claude

- **Size:** 224 B, `0x0015ADD0`–`0x0015AEB0` (SLES_539.74, `asm/SLES_539.74/game_15A050.s`).
- Neighbour `func_0015AEB0` (matched) does the same entry lookup:
  `idx < 0 || idx >= [obj+0xC] -> 0`, else `[obj+0x1C] + (idx << 4)`.

## What it does

Bounds-check `idx`, load `node = *(Pool->entries + idx*16)`, walk the chain
`node = node->0x64` while non-null; per node: if a loop-carried `mark` is 0,
`(s16)node->6 == 8` and `node->0x50 != 0` it "fits" (`size = (u16)node->0x28 * 4`);
if it fits and `remaining >= size` subtract `size` from `remaining`, else
`total += (u16)node->0x28`; also `total += 4` when `(s16)node->6 < 9`.
Return `Pool->0x4 - total`, or 0 for a bad index. `remaining` starts as
`Pool->0x14 - Pool->0x10`.

## The tricky bits (mine vs original)

1. **First-iteration test value:** the loop-head test is `bnez $v0` on the
   loop-carried `mark`; first iteration `mark = lw $v0, 0x10(a0)` (same load
   that feeds `subu $a3,$a1,$v0` for `remaining`), later iterations
   `lh $v0, 0x36(t1)` — and that `lh` sits in the **delay slot of the bottom
   `bnel $t1,$zero` back-edge** (executes with node==0 too, reads 0x36, dead).
   My `while` keeps `mark` in `$a3` with `lh` in program order + `bnez $t2` +
   nop; the original has it as a test-temp in `$v0`.
2. **Register allocation shifted by one:** mine node=`$t2` total=`$t1`
   size=`$t0` remaining=`$a2` mark=`$a3`; original node=`$t1` total=`$t0`
   size=`$a2` remaining=`$a3` mark/temp=`$v0`. Declaring locals in the
   original's order did not move the allocation.
3. **Block placement:** original's `fits=0` else is one **far cold block**
   (at +0xC8, `b` back to the check block) shared by the three tests, and the
   then-block falls through into the check; mine's then-block branches over an
   inline else. Also original uses `slt $at` + `bnez $at` for `remaining <
   size`; mine got `slt $v0`.

## Best C

`notes/needs-claude/func_0015ADD0_best.c` (local `Chain`/`Pool` structs,
&&-chain with single else). Best `--show` tail is in the git history? no —
diff not committed; reproduce with
`tools/try_match.py <file> func_0015ADD0 0x15ADD0 --show -- -O3`.

## Tried (5 attempts, ~35 min)

- Three separate `fits = 0` if/else-if arms: score 48, all inline.
- Single `if (mark == 0 && node->type == 8 && node->ref != 0) {...} else {fits=0;}`
  (shared cold block idea from idioms.md line 264/105): score 43.
- Guard `if (idx < 0 || idx >= count) return 0;` matches the original's
  `bltz` + shared return-0 stub exactly.
- Declaration-order swap (idioms.md "Saved registers follow declaration
  order"): no change (still 43).
- `tools/permute.py func_0015ADD0 --run 600` **failed**: `FileNotFoundError:
  'cpp'` — the permuter cannot run in the factory worktrees (no `cpp` on
  PATH). Needs fixing or a wrapper.
- Idioms checked and not the cause: divbyzerocheck (no divides), throw()
  (no frame), branch-likely null checks (no calls). The bnel+delay-slot
  preload + `$t9`-free chain walk resembles idioms.md "Unrolled copy loop"
  only weakly.
