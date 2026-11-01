CLASS reorder+register score=4 (4 words differ, 168 vs 168 bytes) — best attempt

# func_0046CEB0 (MENU, 176 B, 0x0046CEB0)

Twin of the matched src/MENU/func_0046CE00.c (same `struct Menu`/`struct Entry`,
same func_2D6A80/func_2D6B20 + 0x2AF8 label calls). This one, instead of the
func_3713C0 guard: stores `func_202530() - 1` into `menu->f18->fA`, calls
func_2D6A80 (7 args, f32 global D_003DF744 into $f12), func_2D38E0(arg1, 0x4A6,
1, -1), func_2D6B20(arg1, f12+0x2AF8, 0x4A6, 0, 0), func_37CEA0(1), returns 1.

## Best C (score 4, src not committed)

```c
// range: 0x46CEB0 0x46CF60
#include "common.h"

struct Entry {
    char pad[0xA];
    s16 fA;
    char pad2[6];
    s16 f12;
};

struct Menu {
    char pad[0x18];
    struct Entry *f18;
    char pad2[4];
    void *f20;
};

M2C_UNK func_2D6B20(s32, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);               /* extern */
M2C_UNK func_2D6A80(s32, M2C_UNK, M2C_UNK, M2C_UNK, f32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_2D38E0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);                    /* extern */
s32 func_202530(void);                                                       /* extern */
void func_37CEA0(s32);                                                       /* extern */
extern f32 D_003DF744 __attribute__((section(".sdata")));

s32 func_0046CEB0(struct Menu *menu, s32 arg1) {
    s32 n = func_202530();
    f32 scale = D_003DF744;

    menu->f18->fA = n - 1;
    func_2D6A80(arg1, menu->f18->f12 + 0x2AF8, 0x18703, -0xE, scale, 0x12, 0);
    func_2D38E0(arg1, 0x4A6, 1, -1);
    func_2D6B20(arg1, menu->f18->f12 + 0x2AF8, 0x4A6, 0, 0);
    func_37CEA0(1);
    return 1;
}
```

## The diff (everything else is byte-identical)

One instruction misplaced: the `lwc1 $f12` of D_003DF744. Original has it at
+0x34 (between `addiu $a3,$zero,-0xE` and `addiu $t0,$zero,0x12`); mine is
hoisted up to +0x20 (right after `lw $v1,0x18($s1)`), so `addiu $a1`/`lui`/`ori`
shift by 4.

```
  +01C  lw  $v1,0x18($s1)      lw  $v1,0x18($s1)
* +020  lwc1 $f12,0x0($gp)     addiu $a1,$v0,-0x1
* +024  addiu $a1,$v0,-0x1     lui   $v0,0x1
  +028  daddu $a0,$s0,$zero    daddu $a0,$s0,$zero
* +02C  lui   $v0,0x1          ori   $a2,$v0,0x8703
  +030  addiu $a3,$zero,-0xE   addiu $a3,$zero,-0xE
* +034  ori   $a2,$v0,0x8703   lwc1  $f12,-0x7B2C($gp)
  +038  addiu $t0,$zero,0x12   addiu $t0,$zero,0x12
```

## Tried

1. Twin's shape: store inline (`fA = func_202530() - 1`), float passed directly
   as the last (7th) arg — score 5, lwc1 came out *late* (+0x44, after `sh`):
   CW treats the global load as aliased by the store and sinks it.
2. `f32 scale = D_003DF744;` as the first statement — structural, score 46:
   scale live across `jal func_202530` → CW spills it to `0($sp)` and burns
   `$f20` (frame grows to 0x40, `mov.s $f12,$f20`).
3. `func_2D6A80(s32, u×4, f32, u, u)` prototype (float param at position 5),
   float inline in the call — no change (score 5).
4. Best (above): `n = func_202530(); f32 scale = D_003DF744;` locals, then the
   store, then the call with `scale` at parameter 5 — score 4: the store and
   t0/t1/a3 now all sit right, only the lwc1 is hoisted too early. The
   scheduler pulls the global load up before the `addiu a1`/`lui`/`ori` group.

mh2 catalogue: read "Arguments loaded in another order" (line 1811), the
"A float argument set up last in yours and first in the original" entry —
tried the real-parameter-position fix (attempt 3), it did not move lwc1.

Untried leads: `#pragma schedule off`? an inline helper returning the f32
(pass the value, "Inline helpers" idiom); permuter (`tools/permute.py
func_0046CEB0 --run 600`) — the diff is exactly one movable load.
