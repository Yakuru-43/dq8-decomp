CLASS structural score=12 (10 words differ, 56 vs 48 bytes)   // best attempts (guard clause, 3-arg)

# func_0026DDA0 (SLES_539.74, 48 B incl. padding, asm range 0x26DDA0-0x26DDD0)

## What it does
Takes its value in **$a2** (three int args, first two unused). Loads
`obj = *(s32 *)arg2`, `link = *(s32 *)(obj + 0x54)`; if `link != 0` calls
`func_00268230(link, ...)` and returns 1, else returns 0.

## Original asm
```
addiu sp,-0x10 / sd ra,0(sp)
lw   $v0, 0x0($a2)
lw   $a0, 0x54($v0)
beql $a0, $zero, .L            # link == 0 -> epilogue
 daddu $v0, $zero, $zero       # the return 0, in the delay slot
jal  func_00268230
 lw   $a1, 0x20($v0)           # !!! $v0 is already 0 here: reads *(0x20)
addiu $v0, $zero, 0x1
.L: ld ra; jr ra; addiu sp,0x10
```

**The crux:** the `lw $a1,0x20($v0)` sits in the `jal` delay slot, *after*
the branch delay slot zeroed `$v0`. So the original reads the second arg
from absolute `0x20`-ish, i.e. the base was the **return-value variable**,
which CW also used for `obj` and zeroed before the load. No plain-C form
with a separate `obj` reproduces this: CW either keeps `obj` live (loads
`a1` early, into the branch delay slot) and emits `bnel` + duplicated
epilogue jump (56-60 B, score 12-14), or reloads.

## Best C (attempts 2/3, score 12)
```c
// range: 0x26DDA0 0x26DDD0
#include "common.h"

extern s32 func_00268230(s32, s32);

s32 func_0026DDA0(s32 arg0, s32 arg1, s32 arg2) {
    s32 obj = *(s32 *)arg2;
    s32 link = *(s32 *)(obj + 0x54);
    if (link == 0) {          /* attempt 3: `if (link != 0) { call; return 1; } return 0;` same */
        return 0;
    }
    func_00268230(link, *(s32 *)(obj + 0x20));
    return 1;
}
```

## What I tried (4 attempts, -O3)
1. 1-arg version — arg landed in $a0 (wrong reg), score 13.
2. 3-arg guard clause — score 12: CW emits `bnel` + `lw a1` in the beql
   delay slot + `b` + separate `daddu v0,0` (duplicated epilogue, 56 B).
3. `if (link != 0) {...} return 0;` — byte-identical to 2.
4. Single `ret` variable used as both base and return (if/else assigning
   1/0) — worse (60 B): CW duplicates the call block (`b` back to it).

## Hints
- The `lw $a1,0x20($v0)`-after-the-zero pattern says: get CW to allocate
  the return variable to $v0, load obj+0x54 into $a0 *before* the branch,
  then load the a1 argument *from $v0* inside the call block. Attempt 4
  got close but CW re-placed the load. This may need the permuter —
  broken on this host (`cpp` missing; see notes/needs-claude/func_00257200.md).
- `func_00268230` (in game_267E20.s) is still asm; its two args are
  (pointer, s32) at least.
