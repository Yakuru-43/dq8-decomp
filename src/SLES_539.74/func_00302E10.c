// range: 0x302E10 0x302F10
#include "common.h"

union Vec4 {
    u128 q;
    f32 f[4];
};

M2C_UNK func_001E69B0(M2C_UNK *, s32, M2C_UNK *, M2C_UNK *, M2C_UNK *, s32, s32); /* extern */
void func_0013B720(M2C_UNK *, M2C_UNK *);                                          /* extern */

s32 func_00302E10(M2C_UNK *elems, s32 count, M2C_UNK *out, M2C_UNK *src) {
    union Vec4 bufB;
    union Vec4 bufA;
    f32 result[0x40];
    M2C_UNK *elem;
    s32 i;

    elem = elems;
    for (i = 0; i < count; elem = (M2C_UNK *)((char *)elem + 0x60)) {
        if (M2C_FIELD(elem, s16 *, 0x46) == 8) {
            bufB.q = *(u128 *)src;
            bufB.f[1] += 20.0f;
            bufA.q = *(u128 *)src;
            bufA.f[1] -= 80.0f;
            if (0 <= func_001E69B0(elem, 1, (M2C_UNK *)&bufA, (M2C_UNK *)&bufB,
                                   (M2C_UNK *)result, 1, 0x11)) {
                *(u128 *)out = *(u128 *)result;
                func_0013B720((M2C_UNK *)((char *)out + 0x10),
                              (M2C_UNK *)((char *)elem + 0x30));
                M2C_FIELD(out, f32 *, 0xC) = 1.0f;
                M2C_FIELD(out, f32 *, 0x1C) = 1.0f;
                return 1;
            }
        }
        i++;
    }
    return 0;
}
