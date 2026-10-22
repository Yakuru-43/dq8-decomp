# func_002FF0D0 (SLES_539.74, 0x002FF0D0, 32 bytes) — factory-3

A lerp: `arg0 + (arg1 - arg0) * arg2 / arg3`, but the signed division is
guarded by a div-by-zero trap the compiler refuses to emit from any C shape
tried.

## Original asm (`asm/SLES_539.74/game_2FE690.s`, also in game_2FE2B0.s,
game_2FE750.s)

```
glabel func_002FF0D0
    /* 1FF0D0 002FF0D0 2310A400 */  subu       $v0, $a1, $a0
    /* 1FF0D4 002FF0D4 1810C200 */  mult       $v0, $a2, $v0
    /* 1FF0D8 002FF0D8 0200E014 */  bnez       $a3, .L002FF0E4
    /* 1FF0DC 002FF0DC 1A004700 */   div       $zero, $v0, $a3
    /* 1FF0E0 002FF0E0 CD010000 */  break      0, 7
  .L002FF0E4:
    /* 1FF0E4 002FF0E4 12100000 */  mflo       $v0
    /* 1FF0E8 002FF0E8 0800E003 */  jr         $ra
    /* 1FF0EC 002FF0EC 21108200 */   addu      $v0, $a0, $v0
endlabel func_002FF0D0
```

The `div` always runs (delay slot of the guard branch); the `break 0, 7`
only on `arg3 == 0`. Same guard shape exists unfused in unmatched code
(`game_29BC60.s:63` and `:91`, `%` by a variable, `bnez/div/break/mfhi`),
so mwccps2 *can* emit it — but from what source construct, unknown.

## Best C (compiles to every word except the guard)

```c
// range: 0x2FF0D0 0x2FF0F0
#include "common.h"

s32 func_002FF0D0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return arg0 + (arg1 - arg0) * arg2 / arg3;
}
```

try_match diff (left = mine):

```
  +000  subu  $v0,$a1,$a0        subu  $v0,$a1,$a0
  +004  mult  $v0,$a2,$v0        mult  $v0,$a2,$v0
* +008  div   $zero,$v0,$a3      bnez  $a3, . + 4 + (0x2 << 2)
* +00C  nop                      div   $zero,$v0,$a3
* +010  nop                      break 0, 7
  +014  mflo  $v0                mflo  $v0
  +018  jr    $ra                jr    $ra
  +01C  addu  $v0,$a0,$v0        addu  $v0,$a0,$v0
DIFF at +0x8: mine 0047001A orig 14E00002  (32 bytes)
```

## Tried (mwccps2 3.0.1b151 -O3, `tools/try_match.py`)

1. `return arg0 + (arg1 - arg0) * arg2 / arg3;` → unguarded `div; nop; nop`.
2. Same with `%` instead of `/` → also unguarded (`mfhi`), so the guard is
   not an automatic `/` or `%` check.
3. `if (arg3 == 0) { return arg0; } ...` → `bnel` + `b` + `daddu` + late
   div/break; no break in the guard position (and wrong semantics anyway).
4. `if (arg3 == 0) { __builtin_trap(); }` → prologue + `jal func_000000`
   (runtime handler), 120 B. Not the inline break.
5. `if (arg3 == 0) { asm("break 0, 7"); }` → compiler error
   "unknown assembler instruction mnemonic" — inline asm statements parse,
   but `break` is not a known mnemonic.

No matched function in `src/` contains a `break 0, 7`, so there is no
precedent for how this project expresses it. Question for Claude: what C
construct (intrinsic, pragma, or statement) makes mwccps2 emit the inline
`bnez <divisor> + div-delay + break 0, 7` guard? If it is a compile option,
which one, and does it deserve a `// flags:` precedent?
