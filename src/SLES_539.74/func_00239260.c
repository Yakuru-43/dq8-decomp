// range: 0x239260 0x239380
#include "common.h"

extern f32 func_0013B6F0(f32 *a, f32 *b);

struct Tagged {
    s32 type;
    union {
        s32 i;
        f32 f;
    } v;
};

struct Unk239260 {
    struct Tagged u[6];
    s32 mode;
    f32 *dst;
};

s32 func_00239260(struct Unk239260 *o, s32 type)
{
    f32 vecA[4];
    f32 vecB[4];
    f32 fx, fy, fz, gw, gh, gi, res;
    struct Tagged *tx, *ty, *tz, *tw;

    if (type != 7) {
        return 0;
    }
    tx = &o->u[0];
    fx = tx->type == 0 ? (f32)tx->v.i : tx->v.f;
    vecA[0] = fx;
    ty = tx + 1;
    if (tx[1].type == 0) {
        fy = (f32)ty->v.i;
    } else {
        fy = ty->v.f;
    }
    vecA[1] = fy;
    fz = tx[2].type == 0 ? (f32)tx[2].v.i : tx[2].v.f;
    vecA[2] = fz;
    vecA[3] = 1.0f;
    tz = tx + 3;
    if (tx[3].type == 0) {
        gw = (f32)tz->v.i;
    } else {
        gw = tz->v.f;
    }
    vecB[0] = gw;
    tw = tz + 1;
    if (tz[1].type == 0) {
        gh = (f32)tw->v.i;
    } else {
        gh = tw->v.f;
    }
    vecB[1] = gh;
    gi = tz[2].type == 0 ? (f32)tz[2].v.i : tz[2].v.f;
    vecB[2] = gi;
    vecB[3] = 1.0f;
    res = func_0013B6F0(vecA, vecB);
    if (o->mode == 3) {
        o->dst[1] = res;
    }
    return 1;
}
