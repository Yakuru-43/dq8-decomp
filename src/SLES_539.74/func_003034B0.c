// range: 0x3034B0 0x3035F0
#include "common.h"

union Vec4 {
    u128 q;
    f32 f[4];
};

void func_0013E090(M2C_UNK *);                                    /* extern */
void func_0013B790(M2C_UNK *, M2C_UNK *, f32);                    /* extern */
void func_0013B7B0(M2C_UNK *, M2C_UNK *, M2C_UNK *);              /* extern */
void func_0013B7D0(M2C_UNK *, M2C_UNK *, M2C_UNK *);              /* extern */
M2C_UNK *func_0014E560(M2C_UNK *, s32);                            /* extern */
M2C_UNK *func_0016DD20(M2C_UNK *, M2C_UNK *, M2C_UNK *, s32);     /* extern */
s32 func_001E6710(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK *, s32, f32); /* extern */
void func_0014E500(M2C_UNK *, M2C_UNK *);                          /* extern */

f32 func_003034B0(M2C_UNK *obj, union Vec4 *src, f32 ang, f32 rate) {
    union Vec4 from;
    union Vec4 to;
    union Vec4 hit;
    union Vec4 move;
    union Vec4 scale;
    M2C_UNK *handle;
    M2C_UNK *sys;
    M2C_UNK *reg;
    s32 hit_r;
    f32 ret;

    if (obj == NULL) {
        return src->f[1];
    }
    sys = (M2C_UNK *)M2C_FIELD(obj, s32 *, 0x54C);
    if (sys == NULL) {
        return src->f[1];
    }
    ret = src->f[1];
    func_0013E090((M2C_UNK *)&scale);
    func_0013B790((M2C_UNK *)&scale, (M2C_UNK *)&scale, 20.0f * rate);
    func_0013B7D0((M2C_UNK *)&from, (M2C_UNK *)src, (M2C_UNK *)&scale);
    func_0013B7B0((M2C_UNK *)&to, (M2C_UNK *)src, (M2C_UNK *)&scale);
    from.f[3] = 1.0f;
    to.f[3] = 1.0f;
    handle = func_0014E560(sys, 0x558);
    reg = func_0016DD20(obj, handle, (M2C_UNK *)&to, 0xE4);
    move.q = src->q;
    move.f[1] += ang;
    hit_r = func_001E6710(handle, reg, (M2C_UNK *)&move, (M2C_UNK *)&hit, 0x11,
                          2.0f * -ang);
    if (0 <= hit_r) {
        ret = hit.f[1];
    }
    func_0014E500(sys, handle);
    return ret;
}
