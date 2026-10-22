// range: 0x3035F0 0x303750
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
void func_00130FD0(M2C_UNK *, M2C_UNK *, s32);                     /* extern */

s32 func_003035F0(M2C_UNK *obj, union Vec4 *src, M2C_UNK *dst, s32 type) {
    union Vec4 from;
    union Vec4 to;
    union Vec4 hit;
    union Vec4 move;
    union Vec4 scale;
    M2C_UNK *handle;
    M2C_UNK *rec;
    M2C_UNK *sys;
    M2C_UNK *reg;
    s32 hit_r;

    if (obj == NULL) {
        return 0;
    }
    sys = (M2C_UNK *)M2C_FIELD(obj, s32 *, 0x54C);
    if (sys == NULL) {
        return 0;
    }
    rec = NULL;
    func_0013E090((M2C_UNK *)&scale);
    func_0013B790((M2C_UNK *)&scale, (M2C_UNK *)&scale, 60.0f);
    func_0013B7D0((M2C_UNK *)&from, (M2C_UNK *)src, (M2C_UNK *)&scale);
    func_0013B7B0((M2C_UNK *)&to, (M2C_UNK *)src, (M2C_UNK *)&scale);
    from.f[3] = 1.0f;
    to.f[3] = 1.0f;
    handle = func_0014E560(sys, 0x300);
    reg = func_0016DD20(obj, handle, (M2C_UNK *)&to, 0x80);
    move.q = src->q;
    move.f[1] -= 40.0f;
    hit_r = func_001E6710(handle, reg, (M2C_UNK *)&move, (M2C_UNK *)&hit, type,
                          80.0f);
    if (0 <= hit_r) {
        rec = (M2C_UNK *)((char *)handle + hit_r * 96);
    }
    func_0014E500(sys, handle);
    if (rec == NULL) {
        return 0;
    }
    func_00130FD0(dst, rec, 0x60);
    return 1;
}
