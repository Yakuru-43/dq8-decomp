// range: 0x00199F30 0x0019A0D0
#include "common.h"

s32 func_0012D528(); /* extern */

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec4;

s32 func_00199F30(s8 *name, Vec4 *out, s32 mode) {
    s32 value;

    if (name == NULL) {
        return 0;
    }
    if (name[1] != '_') {
        return 0;
    }
    if (name[0] < 'a' || name[0] >= 'w') {
        return 0;
    }
    value = func_0012D528(name + 2);
    if (value < 0) {
        return 0;
    }
    if (value >= 100) {
        return 0;
    }
    if (mode != 0) {
        out->x = 4000.0f * (f32)value + (f32)-56000;
        out->y = 0.0f;
        out->z = 4000.0f * (f32)(name[0] - 0x61) + (f32)-40000;
        out->w = 1.0f;
    }
    if ((u32)(mode - 1) < 2) {
        value = func_0012D528(name + 2);
        out->x = 16000.0f * (f32)value + (f32)-56000;
        out->y = 0.0f;
        out->z = 16000.0f * (f32)(name[0] - 0x61) + (f32)-40000;
        out->w = 1.0f;
    }
    return 1;
}
