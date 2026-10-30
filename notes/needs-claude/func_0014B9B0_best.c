// best attempt: CLASS structural score=33 (140 vs 148 bytes)
// range: 0x14B9B0 0x14BA50
#include "common.h"

void func_0014B9B0(f32 *arg0, u8 *arg1, f32 *arg2) {
    f32 f;
    s32 b;
    u32 m;

    b = arg1[0];
    if (b < 0) {
        m = ((u32)b >> 1) | (b & 1);
        f = (f32)m + (f32)m;
    } else {
        f = (f32)b;
    }
    arg0[0] = 1.0f * f * arg2[0];
    b = arg1[1];
    if (b < 0) {
        m = ((u32)b >> 1) | (b & 1);
        f = (f32)m + (f32)m;
    } else {
        f = (f32)b;
    }
    arg0[1] = 1.0f * f * arg2[1];
}
