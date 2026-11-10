// best draft for func_00212D40 (attempt 2, CLASS structural score=14, 13 words,
// 76 vs 72 bytes) — resume here. Remaining walls vs orig:
//  * orig materializes the counter address ONCE (`addiu v1,a0,0x48C` at +0x18,
//    between the first beqz and the second guard's reload) and reaches BOTH
//    stores through it (`sw zero,0(v1)` shared by guard1-taken and guard2-taken);
//    mine kept `lw v1,0x48C(a0)` at +0x1C and `sw zero,0x48C(a0)` at +0x3C.
//  * guard2 shape: orig `slti v0,v0,0x10` INTO v0 (not $at!) + `bnez v0,+5w`,
//    delay `addiu v1,a0,0x48C`, then `b +5w` delay `addiu v0,zero,0x40`,
//    `b -7w` (back to guard1 region), `sw zero,0(v1)`, `addiu v0,zero,0x80`,
//    jr — i.e. return-value 0x40 set in a delay slot on the not-taken path,
//    0x80 set AFTER the sw; mine emitted beql+0x80-in-delay + 0x40 (score 14).
//  * the wrap path (>=0x1F) stores zero in the delay slot of a `b` back to the
//    reload at +0x1C.
// range: 0x212D40 0x212D90
#include "common.h"

s32 func_00212D40(char *arg0) {
    s32 *ctr;
    s32 v;

    M2C_FIELD(arg0, s32 *, 0x48C) = M2C_FIELD(arg0, s32 *, 0x48C) + 1;
    if (M2C_FIELD(arg0, s32 *, 0x48C) >= 0x1F) {
        M2C_FIELD(arg0, s32 *, 0x48C) = 0;
    }
    ctr = (s32 *)(arg0 + 0x48C);
    v = *ctr;
    if (v >= 0x10) {
        return 0x40;
    }
    *ctr = 0;
    return 0x80;
}
