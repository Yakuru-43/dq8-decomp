// range: 0x199CD0 0x199E80
#include "common.h"

extern f32 func_00129CC0(f32);

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} __attribute__((aligned(16))) Vec4;

s32 func_00199CD0(Vec4 *arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4, s32 arg5) {
    Vec4 pos;
    f32 q0;
    f32 q1;
    f32 fx;
    f32 fy;
    s32 ix;
    s32 iy;
    s32 sign;

    q0 = 0.0f;
    q1 = 0.0f;
    pos = *arg0;
    pos.x = pos.x - (f32)-56000;
    pos.z = pos.z - (f32)-40000;
    if (arg5 == 0) {
        q0 = pos.x / 4000.0f;
        q1 = pos.z / 4000.0f;
    } else if ((u32)(arg5 - 1) < 2) {
        q0 = pos.x / 16000.0f;
        q1 = pos.z / 16000.0f;
    }
    ix = (s32)func_00129CC0(0.5f + q0);
    iy = (s32)func_00129CC0(0.5f + q1);
    fy = q1 - (f32)iy;
    fx = q0 - (f32)ix;
    if (arg1 != 0) {
        *arg1 = ix;
    }
    if (arg2 != 0) {
        *arg2 = iy;
    }
    if (arg3 != 0) {
        sign = 1;
        if (fx <= 0.0f) {
            sign = -1;
        }
        *arg3 = sign;
    }
    if (arg4 != 0) {
        sign = 1;
        if (fy <= 0.0f) {
            sign = -1;
        }
        *arg4 = sign;
    }
    return 1;
}
