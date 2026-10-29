CLASS structural score=26 (25 words differ, 116 vs 120 bytes) — best attempt, -O3

# func_0033FDD0 — needs Claude

- Size: 128 B (0x33FDD0..0x33FE50, incl. padding). Binary SLES_539.74.
- Shape: appends a pair to a global array:

```
daddu $s0,$a0,$zero        ; s0 = arg0 (before the first jal!)
jal   func_001667C0         ; get-tagged-int(arg0), result unused
addiu $s0,$s0,0x8           ; (f1 delay slot) s0 = arg0+8
daddu $a0,$s0,$zero
jal   func_00166760         ; get-tagged-when-tag0(arg0+8)
daddu $s0,$v0,$zero         ; (delay) s0 = result
lw    $a1,D_003E12BC($gp)
jal   func_0014D700
daddu $a0,$v0,$zero         ; (delay) passes $v0 RAW, no $s0 copy
lui   $v1,hi(D_00453800); lui $a0,hi(D_00453804)
lw    $a3,lo(D_00453800)($v1)   ; count into $a3
lw    $a1,lo(D_00453804)($a0)   ; base into $a1
lui   $v1,hi(D_00453800)        ; hi reloaded
sll   $a2,$a3,3                 ; count*8 into $a2
addiu $a0,$a3,1
sw    $a0,lo(D_00453800)($v1)   ; count++ BEFORE the pointer add
addu  $v1,$a1,$a2
sw    $v1,D_003E12D8($gp)
sw    $s0,0x0($v1)              ; entry[0] = f2 result
lw    $v1,D_003E12D8($gp)       ; global RELOADED for the second store
sw    $v0,0x4($v1)              ; entry[1] = 14D700 result
ld    $ra,0x10($sp); addiu $v0,$zero,1; lq $s0; jr $ra; addiu $sp,$sp,0x20
```

- Frame 0x20, `sd $ra,0x10($sp)`, `sq/lq $s0` at 0x0. Returns 1.

## Best C (116 B, CLASS structural 26; every head word present, one folded short)

```c
// range: 0x33FDD0 0x33FE50
#include "common.h"

s32 func_0014D700(s32, s32);   /* extern */
s32 func_001667C0();            /* extern */
s32 func_00166760();            /* extern */
extern s32 D_003E12BC;
extern s32 D_003E12D8;
extern s32 D_00453800 __attribute__((section(".data")));
extern s32 D_00453804 __attribute__((section(".data")));

s32 func_0033FDD0(char *arg0) {
    s32 temp_s0;
    s32 temp_v0;
    s32 count;

    temp_s0 = (s32)arg0;
    func_001667C0(temp_s0);
    temp_s0 = temp_s0 + 8;
    temp_s0 = func_00166760(temp_s0);
    temp_v0 = func_0014D700(temp_s0, D_003E12BC);
    count = D_00453800;
    D_00453800 = count + 1;
    D_003E12D8 = D_00453804 + count * 8;
    *(s32 *)D_003E12D8 = temp_s0;
    *(s32 *)(D_003E12D8 + 4) = temp_v0;
    return 1;
}
```

## Diff summary (vs original, --show -O3, ver 3.0.1b151-050317)

- Head: CW folds my `temp_s0 + 8` pass into ONE `addiu $a0,$s0,8` in the
  second jal's delay slot (mine 116 B); the original materializes
  `addiu $s0,$s0,8` (f1 delay) **and** `daddu $a0,$s0,$zero` (120 B).
- f3's first arg: original passes `$v0` raw (f2's result still live); mine
  copies `daddu $a0,$s0,$zero`.
- Tail: mine puts count in `$a1`/`$a2`/`$v1`; original keeps count in `$a3`,
  count*8 in `$a2`, base in `$a1`, count+1 in `$a0` — and hoists both
  `lui`s before the two `lw`s, then reloads `lui $v1,hi(D_00453800)`.
- The `sw/lw/sw` on D_003E12D8 (store, store through reg, reload, store+4)
  already matches word for word with the C spelling above.

## What was tried (3 try_match attempts, all the same CLASS/score)

1. `func_001667C0(arg0); temp_s0 = func_00166760(arg0 + 8);` — same fold.
2. Separate `char *p` walking local (`p = arg0; f(p); p = p + 8; s0 = f(p)`)
   — same fold, CW still passes `addiu $a0,$s0,8` in the delay slot.
3. Single reused `s32 temp_s0` for arg0 → +8 → f2 result (above) — same.
   Not tried yet: permuter (`tools/permute.py func_0033FDD0 --run 600`),
   `-O4,p`, K&R vs prototyped 166760 (true sig is `s32 func_00166760(char *)`,
   see src/SLES_539.74/func_00166760.c), `char *` typed temp,
   idioms "Constant in a `b` delay slot"/"Register clusters swapped around
   an or/addu" (operand-order of `+`), reading mh2 Index for scheduling.

Notes: D_003E12BC/D_003E12D8 are gp-relative (.sdata); D_00453800/804 .data.
Neighbour func_0033FE50 (matched) sets D_00453804 = func_0014E920(x*8, D_003E12BC)
— so D_00453804 is the base of an array of 8-byte entries, D_00453800 its count.
func_001667C0 is the tagged getter, func_00166760 reads value iff tag==0.
