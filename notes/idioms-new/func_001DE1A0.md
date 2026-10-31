## A shared tail assignment that lands in every arm: duplicate it into each arm
Sign: an assignment the obvious C puts after an if/else or switch (a trailing
`buf[3] = 1.0f;` before shared code) where the original stores it once per arm:
`sw $v0,N($sp)` at the end of **each** arm — one inside the arm's `b <join>`
delay slot (its `lui $v0,0x3F80` hoisted to the arm top), one as the last arm's
last statement — and the join block is bare (`addiu $a0,$sp,N; jal; daddu $a1,$a0`).
One shared statement after the chain gives a single store in the join block
(mine 4–8 B short, CLASS structural, score ~74 with every other block
word-identical).
Fix: write the assignment inside every arm, just before each `break;` / arm end;
CW then folds each copy into that arm's exit and hoists the constant load itself.
Same function, paired rule: the first conditional store after the call is
`if (out[0].tag == 3) { x0 = buf[0]; *(f32 *)(out[0].bits + 4) = x0; }` — the
value load written **inside** the success block comes out `beql` with the
annullable `lwc1 $f0,0x40($sp)` in the delay slot; a temp assigned before the
test gives a plain `beq` there instead (tests 2/3 keep plain `beq` and are fine
with pre-test temps, whose loads land in the pre-test block / the `beq` delay
slot).
Example: src/SLES_539.74/func_001DE1A0.c
Solved: func_001DE1A0 2026-10-29 Qwen factory-1, func_0034E4F0 2026-10-30 Qwen factory-3 (same store duplicated into both if/else arms, join block bare)
