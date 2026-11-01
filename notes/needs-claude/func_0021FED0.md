# func_0021FED0 — needs-claude

Best attempt: `CLASS structural score=17 (14 words differ, 252 vs 264 bytes)`
(everything before +0x84 matched word-for-word; only the tail block after the
`bnez $at` on `f1F34 < 0` differs, 3 words missing).

Size 0x110 (code 264 B + padding). Clear/reset on the object at arg0:
byte0=0; loop1 over 16 `s16` at `arg0+2i+0x6A` clear if `< (s16)arg0[0x44]`
(store in the `bnel` delay slot); loop2 over 16 `s16` at `arg0+2i+0x4A` with
the same guard against `arg0[0x46]`, and inside it the slot chain over
`*(char **)(arg0+4i+4)` with `func_00222320(ptr,0)` / `func_002E5800(ptr,-1,-1)`
and the `f1624 = f1F34` copy in the final `b` delay slot. `return 1;`.
Twin (zero-everything variant, already matched): src/SLES_539.74/func_002203B0.c —
same do-while + M2C_FIELD style, byte-exact.

Best C (the draft that gives score 17; loop1 + loop2 entry + guard chain all
matched exactly; also kept at notes/needs-claude/func_0021FED0_best.c):

```c
// range: 0x21FED0 0x21FFD8
#include "common.h"

void func_00222320(char *, s32);
void func_002E5800(char *, s32, s32);

s32 func_0021FED0(char *arg0) {
    s32 var_a1;
    s32 var_s0;
    char *temp_v1;
    char *temp_v1_2;
    char *temp_v1_3;
    char *temp_a0;

    M2C_FIELD(arg0, s8 *, 0) = 0;
    var_a1 = 0;
    do {
        temp_v1 = arg0 + (var_a1 * 2);
        if (M2C_FIELD(arg0, s16 *, 0x44) < M2C_FIELD(temp_v1, s16 *, 0x6A)) {
            M2C_FIELD(temp_v1, s16 *, 0x6A) = 0;
        }
        var_a1 += 1;
    } while (var_a1 < 0x10);
    var_s0 = 0;
    do {
        temp_v1 = arg0 + (var_s0 * 2);
        if (M2C_FIELD(arg0, s16 *, 0x46) < M2C_FIELD(temp_v1, s16 *, 0x4A)) {
            M2C_FIELD(temp_v1, s16 *, 0x4A) = 0;
            temp_v1_3 = arg0 + (var_s0 * 4);
            temp_a0 = M2C_FIELD(temp_v1_3, char **, 4);
            if (temp_a0 != NULL) {
                if (M2C_FIELD(arg0, s8 *, 1) != 0) {
                    func_00222320(temp_a0, 0);
                    temp_a0 = M2C_FIELD(temp_v1_3, char **, 4);
                    if (0 <= M2C_FIELD(temp_a0, s16 *, 0x1F34)) {
                        func_002E5800(temp_a0, -1, -1);
                        temp_v1_2 = M2C_FIELD(temp_v1_3, char **, 4);
                        M2C_FIELD(temp_v1_2, s16 *, 0x1624) =
                            M2C_FIELD(temp_v1_2, s16 *, 0x1F34);
                    }
                }
            }
        }
        var_s0 += 1;
    } while (var_s0 < 0x10);
    return 1;
}
```

## The one block that differs (orig 21FF94.., mine lacks 3 words)

    21FF94  sll   $v0,$s0,2      ; recompute i*4 — MINE: absent, reuses s2
    21FF98  addiu $a1,$zero,-1
    21FF9C  addu  $v0,$s1,$v0
    21FFA0  daddu $a2,$a1,$zero
    21FFA4  jal   func_002E5800
    21FFA8   addiu $s2,$v0,4     ; s2 re-materialized in the jal slot
    21FFAC  lw    $v1,0($s2)     ; third load of *(char**)(arg0+4i+4)
    ...
    21FFB8  b     <loop2 join>
    21FFBC   sw   $v0,0x1624($v1)

The original re-materializes the slot address (sll/addu/addiu into $s2, in the
`jal func_002E5800` delay slot) for the third load, even though $s2 already
holds it from the `beqz $a0` delay slot at 21FF6C (`lw $a0,0($s2)` reload after
`func_00222320` — mine matches there). CW keeps my single `temp_v1_3` local
CSE'd in $s2 and drops the recompute, so I end 12 B short and the epilogue
lands at +0xE4 instead of +0xF0.

## What I tried
1. Twin style, one `temp_v1_3 = arg0 + (var_s0 * 4)` + three
   `M2C_FIELD(temp_v1_3, char **, 4)` — everything matches except the 3-word
   recompute block above (score 17, structural).
2. `temp_v1_3 = arg0 + (var_s0 * 4);` reassigned just before the third load →
   CW treats it as a new SSA value, allocates $s3 across the calls: frame
   0x50 vs 0x40, score 63. Worse.
3. Third load written as `M2C_FIELD(arg0 + (var_s0 * 4), char **, 4)` inline
   (no temp) → still $s3, frame 0x50, score 63.

## Ideas for Claude
- A spelling where the third load's base is derived from `var_s0` again but
  CW can't CSE it into $s2 and *doesn't* need a new callee-saved (the
  recompute in the original dies right after the `addiu $s2,$v0,4` — scratch
  regs only). Maybe `volatile`-free pointer arithmetic on a `char **` local,
  or assigning through a second `char **` typed temp:
  `slot = (char **)(arg0 + (var_s0 * 4) + 4); ... slot = ...; ptr = *slot;`
  (idioms-new/func_00233C40 "split the expression" family).
- mh2 catalogue entries consulted: none specifically fit; this is the
  reload/CSE family (idioms.md "Field load CSE'd where the original reloads",
  but here it's the *address* CSE'd where the original re-materializes —
  the inline-member-accessor trick may be the way: a `char **Slot(...)`
  member/inliner that CW refuses to CSE across the two calls).
- `0 <= M2C_FIELD(temp_a0, s16 *, 0x1F34)` (constant-left, idioms.md) gave the
  `slt $at,$v0,$zero; bnez $at` exactly — keep that spelling.
