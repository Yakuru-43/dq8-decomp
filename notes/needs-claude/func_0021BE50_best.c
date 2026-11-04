// best attempt for func_0021BE50 (CLASS register-only score=20, 412/412 bytes)
// diff is pure float register numbering + second-mul operand order; see .md
// range: 0x21BE50 0x21BFF0
#include "common.h"

typedef union Vec4BE50 {
    /* 0x00 */ u128 q;
    /* 0x00 */ struct {
        /* 0x00 */ f32 x;
        /* 0x04 */ f32 y;
        /* 0x08 */ f32 z;
        /* 0x0C */ f32 w;
    } v;
} Vec4BE50;

void func_0021BE50(f32 *dst, void *src, s32 count, s32 mode, Vec4BE50 scale) {
    f32 *in;
    s16 *in16;
    s8 *in8;
    s32 i;
    f32 k;
    f32 sx;
    f32 sy;
    f32 sz;

    if (mode == 0x20) {
        in = (f32 *)src;
        for (i = 0; i < count; i++) {
            dst[0] = in[0];
            dst[1] = in[1];
            dst[2] = in[2];
            dst[3] = 0.0f;
            dst += 4;
            in += 3;
        }
    } else if (mode == 0x10) {
        in16 = (s16 *)src;
        k = 0.000030517578125f;
        sx = scale.v.x;
        sy = scale.v.y;
        sz = scale.v.z;
        for (i = 0; i < count; i++) {
            dst[0] = (k * (f32)in16[0]) * sx;
            dst[1] = (k * (f32)in16[1]) * sy;
            dst[2] = (k * (f32)in16[2]) * sz;
            dst[3] = 0.0f;
            dst += 4;
            in16 += 3;
        }
    } else if (mode == 8) {
        in8 = (s8 *)src;
        k = 0.0078125f;
        sx = scale.v.x;
        sy = scale.v.y;
        sz = scale.v.z;
        for (i = 0; i < count; i++) {
            dst[0] = (k * (f32)in8[0]) * sx;
            dst[1] = (k * (f32)in8[1]) * sy;
            dst[2] = (k * (f32)in8[2]) * sz;
            dst[3] = 0.0f;
            dst += 4;
            in8 += 3;
        }
    }
}
