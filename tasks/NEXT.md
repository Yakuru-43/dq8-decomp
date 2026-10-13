# Next tasks for Qwen

Work top to bottom. The first `- [ ]` line is your task: open its file, do
it, run its check, then tick it `- [x]` and log it in `notes/weekly/`.
Each task ends in its own commit through `tools/gate.sh`. Don't push.

## Phase 0: clean-up (week of 13 Oct)
- [x] 0.1 Honest progress in the README: `tasks/0.1-readme-progress.md`
- [x] 0.2 `tools/watch.py` counts like the README: `tasks/0.2-watch-progress.md`
- [x] 0.3 Tag the 43 files with contrived C: `tasks/0.3-tag-permuter-artifacts.md`

When all three are ticked, stop and write "Phase 0 done" with the README's
new numbers in `notes/weekly/`. Claude writes the Phase 1 tasks next
(function database and queue); don't start the factory before they exist.

## Phase 1: function database and work queue (weeks 1–2)
All four tasks build one script, `tools/funcdb.py`; do them in order. Its
outputs (`build/funcdb.tsv`, `build/queue.tsv`) are git-ignored; only the
script is committed, once per task.
- [x] 1.1 One row per game function: `tasks/1.1-funcdb-rows.md`
- [x] 1.2 Callers, callees, strings, translation unit: `tasks/1.2-funcdb-calls-strings.md`
- [x] 1.3 The work queue: `tasks/1.3-queue.md`
- [x] 1.4 The Phase 1 check: `tasks/1.4-funcdb-check.md`

When 1.4 passes, stop: Claude picks the 50 pilot functions next (Phase 2).
Don't start the factory until `tasks/pilot.md` exists.

## Phase 2: pilot (weeks 2–3)
- [ ] 2.1 Qwen's 40 pilot functions, measured: `tasks/pilot.md`

Claude does the other 10 (prompt C4) and then reviews the whole pilot (C5).
After 2.1, stop: the factory starts only when Claude has re-estimated the plan.
