# Plan summary

Source: the plan doc (Roadmap, Plan, Runbook tabs), 2026-10-13. This page
replaces it for day-to-day work. Goal: all remaining game code (2,682 KB in
8,124 functions on 13 Oct) rebuilt from `src/` byte for byte. Start: 146 KB
of 2,828 KB (5.2%) matched. Progress is counted in **code bytes**.

## Who does what
- **Qwen** (local, free, always on): volume work. It works `tasks/NEXT.md`,
  runs the function factory, collects evidence, and runs the gate.
- **Claude** (Pro, scarce): things that unlock many functions at once:
  build fixes, type and class headers, hard functions, the weekly audit and
  next week's tasks.
- **The user**: restarts Qwen after the laptop sleeps, reviews, pushes once a day.
- **`tools/gate.sh`** decides what can be committed; a hook enforces it.

## Stages and gates
| Stage | Weeks | Steps | Gate |
|---|---|---|---|
| A Get ready | 1 | 1 pause the permuter · 2 CLAUDE.md, gate, hook · 3 Phase 0 clean-up (`tasks/0.*`) | gate passes on HEAD; README shows 29.8% of functions / 5.2% of code |
| B Measure | 1–3 | 4 `tools/funcdb.py` + `build/queue.tsv` · 5 pilot: 50 functions (Qwen 40, Claude 10) | every remaining function has a queue row and a blocker class; pilot rates recorded |
| C Unblock, in order | 3–6 | 6 jump tables (129 fn, 199 KB) · 7 C++ build path · 8 entry inside (98 fn, 41 KB) · 9 `%hi/%lo` link failures (130 fn, 46 KB) | ≥ 10 matches per family |
| D Types + factory | 4 on | 10 type evidence · 11 headers in `include/game/` · 12 function factory daily · 13 weekly cycle | ≥ 10 matches per header; ~25% of code by week 12, ~50% by week 26 |
| E Finish | ~40–78 | 14 large functions, `NONMATCHING` leftovers · 15 names, Sony SDK identified (not decompiled) | everything built from `src/`, six checksums pass |

Decision at the pilot: if Qwen matches < 20% of 65–256 B functions, Claude
spends more time on types before the factory scales up.

## Weekly cycle (from week 4)
Mon Claude audits last week (fresh-clone build, 20 random new files, lint) ·
Tue–Wed Claude writes headers · Thu Claude solves `needs-claude` functions and
adds each idiom to the skill · Fri Claude writes next week's tasks ·
every day Qwen runs the factory.

## Hand-off files
| File | Written by | Read by | Holds |
|---|---|---|---|
| `CLAUDE.md` | Claude | both, every session | standing rules |
| `tasks/PLAN.md` | Claude | both | this page |
| `tasks/NEXT.md` | Claude (Fri) | Qwen | ordered task list; first `- [ ]` is next |
| `tasks/<id>-<name>.md` | Claude | Qwen | one task: goal, steps, files, a pass/fail check |
| `.claude/skills/match-function/` | Claude | Qwen | the factory loop and the idioms list |
| `build/queue.tsv` (git-ignored) | Qwen | both | one row per function: state `todo / claimed / matched / stuck / needs-claude` |
| `notes/needs-claude/<func>.md` | Qwen | Claude (Thu) | best C, diff, what was tried |
| `notes/weekly/<YYYY-Www>.md` | Qwen, daily | Claude (Mon) | what was done, functions and bytes matched |
| `build/gate.ok`, `build/gate.log` | `tools/gate.sh` | the hook, you | last tree that passed; build log |

## Tools
- `tools/verify.py <src file>`: the match test (`autodecomp.verify()`).
- `tools/try_match.py <file> <func> <vram> --show [--bin <bin>] -- -O3`: side-by-side diff.
- `tools/lint_contrived.py <files>`: the no-contrived-C rules.
- `tools/gate.sh`: clean build of the staged tree, six SHA-1s, forbidden
  paths, lint. `--head` checks HEAD (before a push).
- `tools/keep_funcs.py`, `tools/readme_progress.py`, `tools/progress.py`,
  `tools/permute.py` (finisher only), `tools/autodecomp.py --retry …`.
