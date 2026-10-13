# DQ8 decompilation: rules for every session

Dragon Quest VIII PAL (SLES-53974), matched byte for byte with CodeWarrior
`mwccps2` 3.0.1b151, `-O3`. The plan, phases and file conventions are in
`tasks/PLAN.md`; read it once per session. These rules are not optional.

## What you work on
- Work the **first open task** in `tasks/NEXT.md` (the first line with `- [ ]`).
  Read its task file, do exactly that, tick it `- [x]` when its check passes.
  Nothing in NEXT.md? Run the function factory (`.claude/skills/match-function/`).
- Stuck on a function after 30 attempts or 45 minutes: write
  `notes/needs-claude/<func>.md` (the asm size, your best C, the
  `tools/try_match.py --show` diff, what you tried), mark its row
  `needs-claude` in `build/queue.tsv`, move on.
- Log what you did to `notes/weekly/<YYYY-Www>.md` (ISO week, e.g. `2026-W42.md`):
  one line per task or batch: date, what, functions matched, bytes matched.

## When a function counts as matched
Only when **both** hold:
1. `tools/verify.py src/<bin>/<func>.c` prints `MATCH` (this is
   `autodecomp.verify()`: compile, link at the real address, compare bytes).
   `try_match.py` is for reading diffs; its `MATCH` is not enough.
2. `tools/gate.sh` passes with the file staged.

## No contrived C
Matching code must read like code a person wrote. `tools/lint_contrived.py`
(run by the gate) refuses:
- `volatile`, except on a hardware register (mark the line `// hw-register`)
- `do { } while (0)` and any other `while (0)`
- comma expressions: `(0, p)`, `if (a = b, c)`
- unused `pad` locals (pad fields inside a struct are fine)
- pasted typedef blocks: never re-declare `s32`, `u8`, `M2C_UNK`… —
  **every file starts with `#include "common.h"`**
- also: `x = x;`, a line that is only `;`, `& 0xFFFFFFFF`, `- -0x10`

If only a trick like these matches, the function is not done: write the
needs-claude note instead. Files tagged `// permuter-artifact` are known debt
waiting for a rewrite; don't add new ones.

## Git
- `src/` changes and tool/doc changes go in **separate commits**.
- Stage files **by name**. Never `git add -A`, `git add .` or `git commit -a`.
- Run `tools/gate.sh` after staging; commit only when it says `gate: PASS`.
  A hook blocks `git commit`/`git push` otherwise.
- **Never push.** The user pushes after review.
- Never commit game data or generated files: `asm/ iso/ extract/ assets/
  build/ linker/`, anything under `asmfunc/`, any binary. The gate refuses them.
- Don't edit `checksum.sha1`, `.claude/`, `CLAUDE.md` or `tools/gate.sh`; ask.

## Progress
Report progress in **code bytes from committed files**, not function counts
(`tools/readme_progress.py`, once task 0.1 is done). Functions under
`asmfunc/` are git-ignored and don't count.

## Build
- `make split && make -j` must end with six `OK` lines. After adding src
  files run `tools/keep_funcs.py`; if it adds anything, split and build again.
- Python is `.venv/bin/python`; the compiler runs under `.toolchain/wibo`.
- Never touch the real DQ8 memory card or the user's saves.
