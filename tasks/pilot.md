# Pilot: 50 functions, measured (Phase 2)

**Goal.** Measure how fast and how often Qwen and Claude match functions of
each size, so the timeline in the plan is re-estimated from real numbers
(prompt C5). Matching all 50 is not the goal; honest measurements are.

**The 50.** Ten per size bucket, all unblocked (`blocker` = `none`), none
with VU0 instructions. Each bucket has up to four named translation units,
two overlay functions, and the rest spread over the main binary by address.
Picked at `3f372cc` from `build/funcdb.tsv` with a fixed random seed.
**Qwen: 40, Claude: 10** (2 per bucket, marked Claude below).

## Rules
1. Follow `.claude/skills/match-function/SKILL.md` for each function,
   including the limit: **stop after 30 attempts or 45 minutes**, whichever
   comes first. Same limit in every bucket: it is part of the measurement.
2. Work your functions in `id` order. Before starting one, set its row in
   `build/queue.tsv` to `claimed`; when done, set it to `matched` or `needs-claude`.
3. **An attempt** is one compile-and-compare run, i.e. one
   `tools/try_match.py <file> <func> <addr> -O3 --show [--bin <binary>]`
   (overlays need `--bin`).
4. **Minutes** are wall-clock time from claiming the function to writing its
   log row, including reading the asm.
5. **Best diff score** is the lowest you reached:
   `*` lines in the `--show` output + |your size − original size| / 4.
   `0` = match. Write `NC` if no draft ever compiled.
6. **Too big to read**: if the function's asm doesn't fit in your context,
   don't force it. Log `result` = `too-big` with the minutes spent, then move on.
7. A match counts only after `tools/verify.py` prints MATCH and the lint is
   silent. Commit matches in batches (`src/` only, through the gate). Each
   failure gets its `notes/needs-claude/<func>.md` note as usual.
8. Don't use the permuter unless the score is already ≤ 5; log `yes` in the
   `permuter` column when you did.

## Log: `notes/pilot.tsv` (committed)
One row per function when you finish it, tab-separated, with this header:
```
id	owner	func	bucket	size	attempts	minutes	result	best_score	permuter	commit	notes
```
- `result`: `match`, `needs-claude` or `too-big`.
- `commit`: the commit holding the match, or `-`.
- `notes`: one short line on what decided it (an idiom, a missing type, a
  register swap left over…). No tabs.
- Claude rows add the share of the weekly Claude limit the function used to
  `notes` (from `/status` before and after), e.g. `usage 3%`.

When Qwen's 40 rows are in, tick 2.1 in `tasks/NEXT.md`, log the totals per
bucket in `notes/weekly/` (matched, median attempts, median minutes), and
stop. Claude reviews the pilot with prompt C5.

## The list
| id | owner | bucket | binary | func | addr | size | tu | autodecomp last |
|---|---|---|---|---|---|---|---|---|
| P01 | Qwen | <=64 B | BATTLE | `func_0047C580` | 0x0047C580 | 32 | - | mismatch |
| P02 | Qwen | <=64 B | SLES_539.74 | `func_00340E10` | 0x00340E10 | 32 | - | mismatch |
| P03 | **Claude** | <=64 B | SLES_539.74 | `func_00182130` | 0x00182130 | 48 | - | mismatch |
| P04 | Qwen | <=64 B | SLES_539.74 | `func_001BA940` | 0x001BA940 | 48 | - | size |
| P05 | Qwen | <=64 B | SLES_539.74 | `func_0030DB70` | 0x0030DB70 | 64 | dq_player_ai.cpp? | mismatch |
| P06 | Qwen | <=64 B | SLES_539.74 | `func_00335B90` | 0x00335B90 | 64 | btl_viscom.cpp? | mismatch |
| P07 | Qwen | <=64 B | SLES_539.74 | `func_002963B0` | 0x002963B0 | 64 | dq_2nd_chk.cpp? | size |
| P08 | **Claude** | <=64 B | SLES_539.74 | `func_0029D750` | 0x0029D750 | 64 | dq_monster_ai.cpp? | mismatch |
| P09 | Qwen | <=64 B | TITLE | `func_00460710` | 0x00460710 | 64 | - | compile |
| P10 | Qwen | <=64 B | SLES_539.74 | `func_00257380` | 0x00257380 | 64 | - | repaired |
| P11 | Qwen | 65-256 B | SLES_539.74 | `func_00220F60` | 0x00220F60 | 80 | - | mismatch |
| P12 | Qwen | 65-256 B | MENU | `func_00464CB0` | 0x00464CB0 | 96 | - | mismatch |
| P13 | **Claude** | 65-256 B | SLES_539.74 | `func_0030FE50` | 0x0030FE50 | 112 | dq_player_ai.cpp? | repaired |
| P14 | Qwen | 65-256 B | SLES_539.74 | `func_001AD6A0` | 0x001AD6A0 | 112 | - | repaired |
| P15 | Qwen | 65-256 B | SLES_539.74 | `func_00337400` | 0x00337400 | 128 | btl_viscom.cpp? | mismatch |
| P16 | Qwen | 65-256 B | SLES_539.74 | `func_0034E590` | 0x0034E590 | 144 | - | mismatch |
| P17 | Qwen | 65-256 B | SLES_539.74 | `func_002787D0` | 0x002787D0 | 176 | - | repaired |
| P18 | **Claude** | 65-256 B | SLES_539.74 | `func_0029BB90` | 0x0029BB90 | 208 | dq_monster_ai.cpp? | repaired |
| P19 | Qwen | 65-256 B | SLES_539.74 | `func_00291520` | 0x00291520 | 208 | dq_2nd_chk.cpp? | repaired |
| P20 | Qwen | 65-256 B | CASINO | `func_00472260` | 0x00472260 | 208 | - | m2c |
| P21 | Qwen | 257 B-1 KB | SLES_539.74 | `func_00242A50` | 0x00242A50 | 288 | - | m2c |
| P22 | Qwen | 257 B-1 KB | SLES_539.74 | `func_00368120` | 0x00368120 | 304 | - | mismatch |
| P23 | **Claude** | 257 B-1 KB | SLES_539.74 | `func_00145C30` | 0x00145C30 | 320 | mg_draw.cpp | mismatch |
| P24 | Qwen | 257 B-1 KB | SLES_539.74 | `func_00356E50` | 0x00356E50 | 352 | playerai_data.cpp | mismatch |
| P25 | Qwen | 257 B-1 KB | SLES_539.74 | `func_00331490` | 0x00331490 | 400 | btl_viscom.cpp | repaired |
| P26 | Qwen | 257 B-1 KB | SLES_539.74 | `func_0030F550` | 0x0030F550 | 432 | dq_player_ai.cpp? | size |
| P27 | Qwen | 257 B-1 KB | TITLE | `func_00460750` | 0x00460750 | 432 | - | m2c |
| P28 | **Claude** | 257 B-1 KB | SLES_539.74 | `func_0025B760` | 0x0025B760 | 432 | - | compile |
| P29 | Qwen | 257 B-1 KB | SLES_539.74 | `func_00101510` | 0x00101510 | 496 | - | - |
| P30 | Qwen | 257 B-1 KB | SHOP | `func_004634C0` | 0x004634C0 | 512 | - | repaired |
| P31 | Qwen | 1-4 KB | SLES_539.74 | `func_00337BD0` | 0x00337BD0 | 1040 | btl_viscom.cpp | repaired |
| P32 | Qwen | 1-4 KB | SLES_539.74 | `func_001BB2A0` | 0x001BB2A0 | 1184 | - | repaired |
| P33 | **Claude** | 1-4 KB | SLES_539.74 | `func_00195CC0` | 0x00195CC0 | 1264 | - | mismatch |
| P34 | Qwen | 1-4 KB | SHOP | `func_00463E80` | 0x00463E80 | 1280 | - | repaired |
| P35 | Qwen | 1-4 KB | CASINO | `func_004615D0` | 0x004615D0 | 1440 | - | compile |
| P36 | Qwen | 1-4 KB | SLES_539.74 | `func_0033DF40` | 0x0033DF40 | 1472 | - | mismatch |
| P37 | Qwen | 1-4 KB | SLES_539.74 | `func_0029D790` | 0x0029D790 | 1600 | dq_monster_ai.cpp? | size |
| P38 | **Claude** | 1-4 KB | SLES_539.74 | `func_002C60C0` | 0x002C60C0 | 1808 | - | m2c |
| P39 | Qwen | 1-4 KB | SLES_539.74 | `func_002B8390` | 0x002B8390 | 3152 | btl_playdata.cpp | compile |
| P40 | Qwen | 1-4 KB | SLES_539.74 | `func_0030DCC0` | 0x0030DCC0 | 3984 | dq_player_ai.cpp | m2c |
| P41 | Qwen | >4 KB | MENU | `func_004723D0` | 0x004723D0 | 4384 | - | compile |
| P42 | Qwen | >4 KB | BATTLE | `func_00462FB0` | 0x00462FB0 | 4624 | - | m2c |
| P43 | **Claude** | >4 KB | SLES_539.74 | `func_00183B80` | 0x00183B80 | 4880 | - | m2c |
| P44 | Qwen | >4 KB | SLES_539.74 | `func_002ED790` | 0x002ED790 | 5024 | - | compile |
| P45 | Qwen | >4 KB | SLES_539.74 | `func_003324B0` | 0x003324B0 | 5648 | btl_viscom.cpp | repaired |
| P46 | Qwen | >4 KB | SLES_539.74 | `func_00365E70` | 0x00365E70 | 6544 | - | repaired |
| P47 | Qwen | >4 KB | SLES_539.74 | `func_002B6090` | 0x002B6090 | 8144 | - | m2c |
| P48 | **Claude** | >4 KB | SLES_539.74 | `func_002F0C10` | 0x002F0C10 | 8368 | - | compile |
| P49 | Qwen | >4 KB | SLES_539.74 | `func_002A89B0` | 0x002A89B0 | 9968 | - | m2c |
| P50 | Qwen | >4 KB | SLES_539.74 | `func_002A4D70` | 0x002A4D70 | 15104 | - | compile |
