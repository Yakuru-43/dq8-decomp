// CLASS structural score=32 (31 words differ, 248 vs 252 bytes)  [best attempt, 2026-10-31]

# func_0015AEF0 — needs Claude

- **Size:** 256 B, `0x0015AEF0`–`0x0015AFF0` (SLES_539.74, `asm/SLES_539.74/game_15AEF0.s`).
- Best C: `notes/needs-claude/func_0015AEF0_best.c`. Reproduce diff with
  `tools/try_match.py notes/needs-claude/func_0015AEF0_best.c func_0015AEF0 0x15AEF0 --show -- -O3`.

## What it does

Hash-table find in a pool/registry object: if `arg1 (key) == 0` return 0; if
`obj[0x1E4] != 0` it copies the name `obj+0x1E4` into a `char buf[0x80]` local
(`func_001340C0()` with a nop delay slot first, then
`func_00133CB8(buf, obj + 0x1E4)` — CW put the a1 setup in that jal's delay
slot) and searches with that; else searches with `key`. Hash over every byte
(`s32 c` temp, **one** `lb`, no shift pair — not `s8`):
`h = ((h & 0xFF) << 8) + c; h %= 101; h &= 0xFF;` then bucket
`node = *(u32 *)((h & 0xFF) << 2 ?+ obj + 0x30)`, chain walk
(`node->0` = record, `node->4` = next): `func_00133F78` is the MSL SIMD
strcmp at 0x133F78 (`asm/SLES_539.74/sdk_128868.s:13607`), called
`func_00133F78(s, *(u32 *)node + 8)` — **no `entry` local**: the original
rematerializes `lw $v0,0($s2)` at all three sites (delay slot of the loop-test
backedge, the `lh` id compare, the return). Id field is `s16` (`lh`, not
`lhu`): `if (id < 0 || *(s16 *)(*(u32 *)node) == id) return *(u32 *)node;`.
Twin context: `func_0016AC80.c` (same strcmp use), `func_0015AEB0.c` (same
pool indexing style).

## State at score 32

Frame `0xC0` matches, prologue/`s0..s2` save order matches, the whole hash
loop (+0x38..+0x74) matches **line for line**, chain walk mostly matches.
Four real diffs left, all small:

1. `p = s; h = 0;` init order: original does `daddu $a1,$s0` **then**
   `daddu $a0,$zero` (+0x30); best.c has them swapped.
2. `if (obj[0x1E4] != 0)`: original `bnel` + `addiu $a0,$sp,0x40` in the delay
   slot; mine plain `bnez` + nop and the buf address materialized late
   (+0B0). Probably fixed by 1/4 (scheduling pressure), try `!= 0` forms.
3. Bucket address (+0x6C): mine `addu $v0,$s2,$v0` (base-first), orig
   `addu $v0,$v0,$s2` (index-first); `(h << 2) + obj + 0x30` and
   `obj + (h << 2) + 0x30` both print base-first. Next try: idioms-new
   `func_00327A70.md` (typed struct-member array: a struct with the bucket
   array at 0x30, `table->buckets[i]`), or a `u32 *` indexed form.
4. Return-0 stubs (+0x98..): mine has **two** `b <epilogue>; v0=0` stubs, the
   original one shared `b LAF8C; ld $ra` stub that the loop-end `return 0`
   falls into (`daddu $v0,$zero,$zero` at LAF88) with the null-check stub as
   `b LAF8C; daddu $v0,$zero,$zero` — idioms.md "Two `return 0` share one
   stub" (mine 4 B short, 248 vs 252).

## Tried (3 attempts, ~25 min)

- Attempt 1 (score 65): `u32 entry` local → extra saved `$s3`, frame 0xD0,
  `lhu` id, `s8 c` sign-extend pairs; all fixed in attempt 2 (→ 32).
- Attempt 3 = best.c (rematerialized loads, `s16`, `s32 c`) → 32.
- mh2 catalogue not consulted (time cut).
