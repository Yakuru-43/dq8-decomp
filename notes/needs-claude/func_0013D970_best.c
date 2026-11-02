// best attempt 2026-11-02 Qwen factory-1 — CLASS structural score=113
// (40 words differ, 160 vs 452 bytes). Plain-C float version; the four VU0
// blocks (lqc2/vsub.xyzw/sqc2, vmul.xyz + vmr32 + vadd.x horizontal sums,
// qmfc2.ni -> mtc1) cannot be emitted by mwccps2 from C.
// range: 0x13D970 0x13DB40
#include "common.h"

typedef struct {
    /* 00 */ f32 x;
    /* 04 */ f32 y;
    /* 08 */ f32 z;
    /* 0C */ f32 w;
} Vec4;

/* Classify segment [a1] .. [a0] against the plane through v0 with
 * half-width k(f12); write hits to out(a2), return their count. */
s32 func_0013D970(Vec4 *v0, Vec4 *v1, Vec4 *out, f32 k) {
    Vec4 d;
    s32 n;
    f32 dd, dv, vv, disc, kk;

    kk = k * k;
    d.x = v1->x - v0->x;
    d.y = v1->y - v0->y;
    d.z = v1->z - v0->z;
    dd = d.x * d.x + d.y * d.y + d.z * d.z;
    dv = d.x * v0->x + d.y * v0->y + d.z * v0->z;
    vv = v0->x * v0->x + v0->y * v0->y + v0->z * v0->z;
    disc = vv - dd * kk;
    if (disc < 0.0f) {
        return 0;
    }
    n = 0;
    kk = kk - dv;
    if (kk == 0.0f) {
        out[n].x = v0->x + d.x * (dv / dd);
        n = 1;
    }
    return n;
}
