## Guard `return 0` peeled into a `beql` delay slot: `if (0 < n) { ... } else { return 0; } return 0;`
Sign: an `if (0 < n) { body }` whose false arm and one or two later tests all land on a
shared `daddu $v0,$zero,$zero; <epilogue>` stub, but the guard branch in the original is
`beql $at,$zero,<epilogue+4>; daddu $v0,$zero,$zero` (zero peeled into the delay slot, the
stub entry skipped), while the shared-stub spelling gives plain `beqz $at,<stub>; nop`
(1 word extra, CLASS structural score 2).
Fix: keep the single trailing `return 0;` for the shared stub **and** add an explicit
`else { return 0; }` to the guard: CW gives the guard its own copy of the zero, peels it
into the `beql` delay slot, and leaves the other jumps on the shared stub.
Example: src/SLES_539.74/func_0016CEE0.cpp
Solved: func_0016CEE0 (3 tries, 2026-11-05, Qwen factory-1)
