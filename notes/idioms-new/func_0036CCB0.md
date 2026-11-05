## Guard branch and loop exit share one target: the "else" body is post-loop code
Sign: an `if (cond) { for (...) {...} } else { calls X }`-looking function where
the guard's `beqz <test>, <block>` and the bottom-test loop's fall-through both
land in `<block>`: the loop test (`slt`+`bnez`) is immediately followed by the
X-calls with no `b` over them. Mine (a real `else`) gets a `b <epilogue>` at the
loop exit and one more saved register (the value only needed by X stays live
through the loop). Also: a pure `sb`/`sw` sitting in the delay slot of a `beqz`
executes on BOTH paths — the store is unconditional in the source, so write it
before the `if` it seems to belong to (or between the preceding call and the
test, whichever keeps source order across the `jal`s).
Fix: write the X-calls after the `if (cond)` block, not as its `else`; the
unconditional store goes between the call before the guard and the guard test.
Example: src/SLES_539.74/func_0036CCB0.c
Solved: func_0036CCB0 2026-11-05 Qwen factory-3
