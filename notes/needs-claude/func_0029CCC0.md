# needs-claude: func_0029CCC0

CLASS structural score=8 (8 words differ, 104 vs 104 bytes)

- Size: 112 bytes (0x29CCC0..0x29CD30, 104 real bytes + 8 pad), `game_29D790` region, asm in `asm/SLES_539.74/game_29CB00.s:152`.
- Signature: data pointer arrives in **$a1** — first arg unused. Returns s32 (0 or `0 < func_00297090(...)`).

## What it does
Three byte guards on `arg1` (+0x00 must be nonzero, +0x01/+0x02 must be zero),
then `p = arg1->w1C`, signed `n = *(s16 *)(p + 0x10)`; if `0 <= n < 2` return
`0 < func_00297090(p)`, else return 0.

## Best C (score 8; everything matches except the last 4 branches)

```c
// range: 0x29CCC0 0x29CD30
#include "common.h"

typedef struct {
    char pad0[0x10];
    s16 count;
} S_cnt;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    char pad3[0x1C - 3];
    S_cnt *cnt;
} S_a;

s32 func_00297090();                             /* extern */

s32 func_0029CCC0(s32 arg0, S_a *arg1) {
    S_cnt *cnt;
    s32 count;

    if (arg1->unk0 == 0) {
        return 0;
    }
    if (arg1->unk1 != 0) {
        return 0;
    }
    if (arg1->unk2 != 0) {
        return 0;
    }
    cnt = arg1->cnt;
    count = cnt->count;
    if (count >= 0) {
        if (count < 2) {
            return 0 < func_00297090(cnt);
        }
    }
    return 0;
}
```

The three byte guards already codegen identically (`beql`/`bnel` with
`daddu $v0, $zero, $zero` in each delay slot).

## Diff (only the `count` block differs; left = mine, right = original)

```
  +030  lh    $v0, 0x10($a0)       lh    $v0, 0x10($a0)
* +034  bltz  $v0, +0x8            bltzl $v0, +0x9        ; likely, and...
* +038  nop                        daddu $v0, $zero, $zero ; ...v0=0 in its delay slot
  +03C  slti  $at, $v0, 0x2        slti  $at, $v0, 0x2
* +040  beqz  $at, +0x5            bnez  $at, +0x3        ; into body, not out
  +044  nop                        nop
* +048  jal   func_00297090        b     +0x4             ; else-path b...
* +04C  nop                        daddu $v0, $zero, $zero ; ...with its own v0=0
* +050  b     +0x2                 jal   func_00297090
* +054  slt   $v0, $zero, $v0      nop
* +058  daddu $v0, $zero, $zero    slt   $v0, $zero, $v0  ; slt stays in-line
```

CW shares my single `return 0` store (one `daddu` at +0x58 targeted by both
fail paths); the original materializes `v0 = 0` separately in the taken delay
slot of each of `bltzl` and the else-`b`, and keeps `slt` in-line in the body.

## What I tried
1. Guard clauses `if (count < 0) return 0; if (count < 2) {...} return 0;`
   → CW range-merges the two tests into `bgezl` + `beql $at` (score 13).
2. `if (count >= 0 && count < 2)` — same output as the nested form (score 8).
3. Nested `if (count >= 0) { if (count < 2) return 0 < f(); }` (score 8).
4. Single tail `ret = 0; ... return ret;` → CW duplicates the epilogue and the
   byte guards lose their branch-likely form (score 28).
5. `if (2 <= count) { return 0; }` constant-on-left → extra word, slti clobbers
   `$v0`, second test gets its own `b` (score 18).

`tools/permute.py func_0029CCC0 --run 600` could not run here: `FileNotFoundError:
'cpp'` (decomp-permuter's preprocessing step; this worktree has no `cpp` on PATH).
Probably an inline helper returning the compare, or a C++ path — see the
"Inline helpers" idiom; I did not get a block placement matching the original's
per-path `v0 = 0` in branch-likely delay slots.
