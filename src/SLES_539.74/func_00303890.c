// range: 0x303890 0x303980
#include "common.h"

union Vec4 {
    u128 q;
    f32 f[4];
};

union Scale {
    u128 q;
    f32 f[4];
    s32 i[4];
};

void func_0013DF10(M2C_UNK *, M2C_UNK *);                                     /* extern */
void func_0013B7B0(M2C_UNK *, M2C_UNK *, M2C_UNK *);                          /* extern */
s32 func_001E69B0(M2C_UNK *, s32, M2C_UNK *, M2C_UNK *, M2C_UNK *, s32, s32); /* extern */

M2C_UNK *func_00303890(union Vec4 *src, M2C_UNK *arg1, M2C_UNK *obj, s32 count) {
    union Vec4 pos;
    union Vec4 to;
    union Scale scale;
    union Vec4 hit;
    s32 idx;

    if (obj == NULL || count <= 0) {
        return NULL;
    }
    func_0013DF10((M2C_UNK *)&scale, arg1);
    scale.i[1] = 0;
    pos.q = src->q;
    pos.f[1] += 5.0f;
    func_0013B7B0((M2C_UNK *)&to, (M2C_UNK *)&pos, arg1);
    func_0013B7B0((M2C_UNK *)&to, (M2C_UNK *)&to, (M2C_UNK *)&scale);
    to.f[3] = 1.0f;
    idx = func_001E69B0(obj, count, (M2C_UNK *)&pos, (M2C_UNK *)&to,
                        (M2C_UNK *)&hit, 0x11, 0);
    if (idx >= 0) {
        return (M2C_UNK *)((char *)obj + idx * 96);
    }
    return NULL;
}
