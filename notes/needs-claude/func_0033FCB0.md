# needs-claude: func_0033FCB0

CLASS structural score=27 (26 words differ, 116 vs 120 bytes) — best attempt.
DIFF at +0xC: mine `0C000000` (jal func_000000) orig `0080802D` (daddu $s0,$a0,$zero).
Everything after +0x1C is identical; my code is one instruction (4 B) short at +0xC..+0x1C.

- Size 128 B (`0x33FCB0`–`0x33FD30`), refs D_003E12C0 D_003E12DC D_00453830 D_00453834,
  calls func_001667C0, func_00166760, func_0014D700.
- Shape: append a 2-word entry to the `D_00453834` table (8-byte slots, count
  `D_00453830++`), published in `D_003E12DC`; entry[0] = func_001667C0(arg0),
  entry[1] = func_0014D700(func_00166760(arg0+8), D_003E12C0); return 1.
  The tail (count/base loads, `count+1` store, gp stores with the reload between
  `sw $s0,0($v1)` / `lw $v1,D_003E12DC` / `sw $v0,4($v1)`) matches my draft exactly.

Original head:
```
    daddu $s0,$a0,$zero      jal func_001667C0
    addiu $s0,$s0,0x8        daddu $a0,$s0,$zero
    jal func_00166760
    daddu $s0,$v0,$zero
```
My best C (5 spellings tried, all compiled to this 4-instruction head, 1 instruction short):
```c
    s32 temp_a0; s32 temp_s0; s32 temp_v0; s32 count;

    temp_a0 = arg0;
    temp_s0 = func_001667C0(temp_a0);
    temp_a0 += 8;                          /* also tried before the call, and */
    temp_v0 = func_00166760(temp_a0);      /* also func_00166760(temp_a0 + 8) */
    temp_v0 = func_0014D700(temp_v0, D_003E12C0);
    count = D_00453830;
    D_00453830 = count + 1;
    D_003E12DC = D_00453834 + (count << 3);
    *(s32 *)D_003E12DC = temp_s0;
    *(s32 *)(D_003E12DC + 4) = temp_v0;
    return 1;
```
What CW does with all spellings: `jal f1; [daddu $s0,$a0,$zero]; addiu $a0,$s0,0x8;
jal f2` — it copies arg0 into s0 in f1's delay slot and folds the `+8` into f2's
arg setup, saving the original's separate in-place bump (`addiu $s0,$s0,8` in f1's
delay slot) + `daddu $a0,$s0,$zero`.

Tried: bump-before-call (notes/idioms-new/func_001DD900.md) in both source positions;
`temp_a0 + 8` as the arg; plain `arg0 + 8`; permuter (fails: `cpp` not installed).
mh2 entries considered by index only, not read: "Delay slots filled or empty",
"Arguments kept or reloaded across calls (static callees)", "Loops and pointer bumps".
Needs a spelling that keeps the incremented local live in its own register so CW
emits the separate `addiu` + `daddu` pair instead of folding.
