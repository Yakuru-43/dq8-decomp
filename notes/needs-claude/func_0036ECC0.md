CLASS structural score=75 (75 words differ, 384 vs 384 bytes) — best attempt, 2026-11-04 Qwen factory-3

# func_0036ECC0

Size 0x180 (384 B), `asm/SLES_539.74/game_36ECC0.s`. No blocker, 6 attempts.

## What it does
Tokenizes `[a1, a2)` (`char *p`, `char *end`): a loop over `p < end` where each
round first requires `memcmp(p, set, 2) != 0 && memcmp(p, set, 1) != 0 &&
memcmp(p, set + 1, 1) != 0` (`func_00130F38` = libc `memcmp`,
notes/sdk_functions.tsv); failures on the **outer** pass do `p += 2/1/1` and
`return p` (one shared stub `b epi; daddu v0,s2`), failures inside the inner
pass fall to the shared latch `p++` + bottom test. Inner body: `s8 c = *p`
(`lb $v1`); `c == 9` (tab) loads `out[1]`, does `p++` **before** the null test
(`beqz` + `addiu $s2` delay slot), writes `*out[1] = 0`, breaks to the tail;
else `out[0]` null-tested, `out[0][n++] = c`. Tail: `out[0]` reload,
`out[0][n] = 0; count++`. `out = (char **)a0 + count` — **stride 4**, not 8:
`sll $v0,$s0,2; addu $s4,$s3,$v0` (a two-pointer `Entry` struct gives `sll 3`).
`set` is two stack bytes `0x8C/0x8D` from gp-data bytes `D_003E0084/5`.

## Best C
`notes/needs-claude/func_0036ECC0.c.draft` (nested positive ifs; the shared
latch needs the `&&`/nested form, NOT `continue`, which jumps to the test).

## Diff / open problems (first diff at +0x10, mine prologue vs orig prologue)
1. CW LICMs `&set[1]` into `$s6` up to the **prologue** and folds the
   `set[1] = D_003E0085` store into `sb $v0,0($s6)`. Original: the store stays
   displacement `sb $v0,0x8D($sp)` and `addiu $s6,$sp,0x8D` appears only at
   0x36ED34, between the 2nd and 3rd memcmp (loop body), reused by both 3rd
   calls (`daddu $a1,$s6,$zero`). Tried: `sep` local assigned there, and
   `set + 1` inline at both sites — identical score 75, both hoisted. The
   spelling must stop CW from unifying the store and the call arg into one web.
2. Register cluster shifted one: mine colors `p→$s1, end→$s0, base→$s2,
   count→$s5, n→$s3`; original `count→$s0, end→$s1, p→$s2, base→$s3, out→$s4,
   n→$s5, sep→$s6` (count is zeroed in the prologue: `daddu $s0,$zero,$zero`).
   Declaration-order permutation not yet tried beyond two drafts.
3. Frame: orig `addiu $sp,-0x90` — locals 0x78..0x8F (24 B) while only 0x8C/8D
   are touched; `char c1; char c2;` instead of `char set[2]` gave 372 B /
   frame 0x80 (score 96), so the buffer really is one `char set[2]` (or bigger;
   see idioms-new func_00350560 "array larger than the loop uses" — maybe
   `set[N]` with N ≥ 5 hits 0x90).
4. Original layout facts to aim for: outer loop entry `b .L0036EDF4` with the
   2nd `sb` in its delay slot; inner entry `b` with `addu $s4,$s3,$v0` in the
   delay slot; back edges `bnel $v0,$zero` with `daddu $a0,$s2,$zero` in their
   delay slots; the tab block sits **after** the return stub
   (0x36EE08 = `beqz $v0,EDDC; addiu $s2,1 / b EDDC; sb $zero,0($v0)`).

## Tried
6 try_match attempts (`-- -O3`): `if/break` outer chain matched shape early;
inner `&&`-chain vs nested ifs (same 75); `TokenOut{char*,char*}` 8-byte
entries (wrong stride); two `char` locals (worse); `sep` local vs inline
`set + 1`. No mh2 catalogue entry consulted (never a near miss: 75 words off).
`tools/permute.py` not run (not a register-order-only diff).
