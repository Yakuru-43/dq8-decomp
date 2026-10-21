# Pilot review (prompt C5), 2026-10-21

50 functions, 10 per size bucket, all unblocked: Qwen 40 (8 per bucket),
Claude 10 (2 per bucket). Rows in `notes/pilot.tsv`; Qwen ran headless on the
DGX Spark (vLLM, Qwen3.8-Flash-Next NVFP4 + MTP), one fresh session per
function, 45-minute limit.

## Results

| bucket | Qwen matched | median min (all / matches) | Claude matched |
|---|---|---|---|
| ≤ 64 B | 4/8 | 16 / 6.5 | 2/2 |
| 65–256 B | 4/8 | 16 / 7.5 | 2/2 |
| 257 B–1 KB | 3/8 | 30 / 20 | 2/2 |
| 1–4 KB | 0/8 | 48 / – | 0/2 |
| > 4 KB | 0/8 | 42 / – | 0/2 (triage only) |

After the pilot Claude solved P02 (Qwen's 32-byte failure): **17 of 50**.
Claude's 1–4 KB pair came close (P33 8 bytes short, P38 down to saved
registers) but needed 45–75 minutes each.

**Plan decision** ("if Qwen matches < 20 % of 65–256 B, Claude spends more time
on types first"): Qwen matched 50 %. The factory scales up as planned.

## Why functions failed

Qwen's 13 failures at ≤ 1 KB:

| family | functions | fix | owner |
|---|---|---|---|
| splat split in the wrong place (a function entered by fallthrough or split mid-body) | P01, P09/P27, P20 | correct the boundaries in `config/` (`entry-inside` family, step 8) | Claude |
| compare kept as a value before the branch | P02 (solved), P22? | idiom: C++ `bool` compared with `false` | in the skill |
| block placement / shared return stub | P14, P15, P25, P30 | idiom: nested ifs with one `return` (partly); more needed | Claude, Thu |
| argument copy order / indirect-call schedule | P16, P04 | open | Claude, Thu |
| unreachable code after an unconditional branch | P29 | open (boot code) | Claude |

Above 1 KB nobody matched. The walls there: m2c cannot decode the PS2 FPU
accumulator ops (`adda/madd/mula/msub.s`, 19 errors in P43), drafts with
dozens of `goto`s that `repair.py` cannot make compile (P46, P47, P48), and
stack frames where several address-taken locals are one big struct (P45, P46,
P50: CodeWarrior drops what it sees as separate dead scalars).

## Root cause found for the overlay split failures

Every overlay file (`BATTLE`, `CASINO`, `MENU`, `SHOP`, `TITLE`) starts with
a 64-byte `MWo3` header whose load address is 0x45EC80; the header is loaded
too, so the code starts at **0x45ECC0**. We strip the header and place the
code at 0x45EC80, so every overlay address is 0x40 too low. Bytes still match
(names follow the encoded addresses), but `jal` targets land 0x40 inside the
real functions and splat starts a "function" there. Test: `jal` targets that
hit a prologue (`addiu $sp, $sp, -N`) when shifted by 0x40 vs not shifted:
BATTLE 356 vs 85, CASINO 578 vs 19, MENU 196 vs 9, SHOP 285 vs 30,
TITLE 21 of 21 vs 0. That explains P01, P09/P27, P20, and 121 of the 128
`entry-inside` functions are in overlays. Fix (Claude, next): overlay vram
0x45ECC0 in the configs and tools, rename the 431 overlay `src/` files
(+0x40), re-split, six checksums.

## New idioms (in the skill since 5a768a3)
- C++ `bool` compared with `false`, `.cpp` files supported by `verify.py`.
- Inline helpers nest one level only; pass the pointer and recompute.
- `0 <= x` (constant on the left) gives `slt $at`.
- One shared return stub = nested ifs with one `return`.
- Struct copies reveal member types; `u128` union for vectors.
- `volatile` with `// thread-shared` for data another thread writes.

## Retry with the new skill (`notes/pilot-retry.tsv`)
Qwen retried its seven ≤ 1 KB failures with the idioms above, one fresh
session each. **P04 matched** (28 min) with an idiom Qwen found itself:
CodeWarrior's virtual call (`lw t9,0xC0(v0); lw t9,0xC4(t9); jalr t9;
daddu a0,v0`, data members declared before the first virtual). P14, P15,
P16, P22 and P25 did not, after 28–45 minutes and 8–16 C shapes each; the
permuter, now run from clean bases, found nothing either. Pilot total:
**18 of 50**.

The five misses are one family: everything matches except an instruction
scheduling or register choice that no C shape moves — block placement around
a shared return stub (P14), a `beql` with a hoisted `daddu v0,0` (P15, P25),
argument-copy order across the a/t registers (P16), a rotated s-register
assignment plus a kept `andi 0xFFFF` (P22). Qwen's notes pin each rule down
with a corpus scan; they are Claude's Thursday work. One solved rule should
unlock the family.

## Remaining work (queue, 2026-10-21)

| bucket | unblocked functions | KB | blocked functions | KB |
|---|---|---|---|---|
| ≤ 64 B | 1,611 | 75 | 15 | 1 |
| 65–256 B | 3,488 | 519 | 140 | 23 |
| 257 B–1 KB | 2,153 | 1,012 | 164 | 81 |
| 1–4 KB | 367 | 623 | 57 | 101 |
| > 4 KB | 23 | 144 | 12 | 96 |

Blocked: jump tables 130 functions / 201 KB, entry-inside 128 / 55 KB,
`%hi/%lo` link failures 130 / 46 KB. Matched so far: 154 of 2,828 KB (5.4 %).

## Timeline, re-estimated

Qwen at pilot rates, on functions ≤ 1 KB only (7,252 functions, 1,606 KB):
about 20 minutes per function on average, so ~145,000 minutes of sessions,
and at 50 % / 50 % / 37.5 % it would match about **680 KB (+24 points)**.

| Qwen running | days for the ≤ 1 KB queue | code matched at the end |
|---|---|---|
| 24 h/day, one session | ~100 days (week ~18) | ~30 % |
| 24 h/day, three sessions in parallel | ~35–45 days (week ~10) | ~30 % |
| ~10 h/day (laptop on in the day) | ~240 days | ~30 % |

The plan's "~25 % by week 12" holds only if Qwen runs around the clock and
in parallel; "~50 % by week 26" needs the 1–4 KB bucket (623 KB), where Qwen
matched 0/8, plus the blocked families (~300 KB, Claude's step 6–9 work).
Idioms raise the rates: every needs-claude family solved goes back to Qwen.

## Recommendations
1. **Qwen works ≤ 1 KB only.** Leave larger rows `todo` for Claude and later.
2. **Run Qwen always-on and in parallel.** vLLM serves several sessions at
   once; the client needs an x86 Linux host because the compiler runs under
   `wibo` (the Spark is ARM): the RTX box (option B) or a second machine.
   Two or three sessions on different translation units roughly multiply
   throughput, since generation is ~55 tok/s per stream.
3. **Claude, next:** the overlay address fix above (unblocks most of
   entry-inside and every overlay split), jump tables (201 KB), then Thursday needs-claude passes on
   the block-placement family.
