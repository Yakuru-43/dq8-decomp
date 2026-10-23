// range: 0x303E30 0x304020
#include "common.h"

union Vec4 {
    u128 q;
    f32 f[4];
};

struct SpawnRec {
    char _pad104[0x104];
    s32 i104;
    s128 q110;
    s32 i120;
    f32 f124;
    s32 _pad128[2];
    s128 q130;
};

f32 func_0013D340(s128 *, s128 *);                                  /* extern */
s32 func_001E6520(M2C_UNK *, s32, M2C_UNK *, M2C_UNK *, s32, s32 *,
                 union Vec4 *, s32, s64);                           /* extern */

void func_00303E30(struct SpawnRec *rec, union Vec4 *pos1, union Vec4 *pos2,
                  char *table, s32 sel, f32 lift) {
    s32 hits[32];
    union Vec4 dst;
    union Vec4 src;
    union Vec4 slots[0x40];
    s32 count;
    s32 i;
    s32 j;

    count = func_001E6520((M2C_UNK *)table, sel, (M2C_UNK *)pos1,
                          (M2C_UNK *)pos2, 0x20, hits, slots, 1, 0);
    for (i = 0; i < count; i++) {
        if (M2C_FIELD(table + hits[i] * 96, s16 *, 0x44) == 1) {
            rec->i120 = 1;
            rec->f124 = func_0013D340((s128 *)pos1, (s128 *)pos2);
            if (pos1->f[1] > pos2->f[1]) {
                rec->f124 = rec->f124 * -1.0f;
            }
            rec->q130 = slots[i].q;
        }
    }
    dst.q = pos2->q;
    src.q = pos2->q;
    dst.f[1] += lift;
    count = func_001E6520((M2C_UNK *)table, sel, (M2C_UNK *)&dst,
                          (M2C_UNK *)&src, 0x20, hits, slots, 1, 0);
    if (count == 0) {
        return;
    }
    for (j = 0; j < count; j++) {
        if (M2C_FIELD(table + hits[j] * 96, s16 *, 0x44) == 1) {
            rec->i104 = 1;
            rec->q110 = slots[j].q;
        }
    }
}
