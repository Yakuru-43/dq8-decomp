// range: 0x13BDA0 0x13BED0
#include "common.h"

extern f32 D_003DF4B4;   /* 3.141592741f */
extern f32 D_003DF554;   /* 6.283185482f */
extern f32 D_003DF560;   /* -3.141592741f */
extern f32 D_003DF564;   /* 6.283185482f */
extern f32 D_003DF568;   /* -3.141592741f */
extern f32 D_003DF56C;   /* 6.283185482f */

f32 func_0013BDA0(s32 mode, f32 a, f32 b, f32 c) {
    f32 d = b - a;
    f32 t = 0.0f;
    f32 r;

    if (!(d <= D_003DF4B4)) {
        d -= D_003DF554;
    }
    if (d <= D_003DF560) {
        d += D_003DF564;
    }
    if (mode == 0) {
        if (d < 0.0f) {
            r = -d;
        } else {
            r = d;
        }
        if (r < c) {
            return b;
        }
        if (d < 0.0f) {
            if (c < d) {
                return b;
            }
            t -= c;
        }
        if (!(d < 0.0f)) {
            if (!(c <= d)) {
                return b;
            }
            t += c;
        }
    } else if (mode == 1) {
        t = d / c;
    }
    r = a + t;
    if (!(r <= D_003DF4B4)) {
        r -= D_003DF564;
    }
    if (r <= D_003DF568) {
        r += D_003DF56C;
    }
    return r;
}
