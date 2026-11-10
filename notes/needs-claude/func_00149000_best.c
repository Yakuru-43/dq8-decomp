// range: 0x149000 0x149240
#include "common.h"

typedef union Vec {
    u128 q;
    struct { f32 x, y, z, w; } v;
    s32 iw[4];
} Vec;

typedef struct Obj {
    u8 pad0[0x14];
    Vec *vec;      /* 0x14 */
    Vec *quatp;    /* 0x18, ->iw[3] used as an int flag */
    s32 w1C;       /* 0x1C */
    u8 pad20[0x9];
    u8 b29;        /* 0x29 */
    u8 pad2A;
    u8 b2B;        /* 0x2B */
    u8 b2C;        /* 0x2C */
    u8 pad2D[0x3];
    Vec buf30;     /* 0x30 */
    Vec buf40;     /* 0x40 */
    Vec buf50;     /* 0x50 */
    Vec quads[4];  /* 0x60 */
} Obj;

void func_00149000(Obj *src, Obj *dst) {
    Vec l60, l50, l40, q3, q2, q1, q0;
    Vec *dv;
    Vec junk;

    if (src->vec == 0) {
        return;
    }
    if (src->vec != 0) {
        l60.q = src->quads[3].q;
    } else {
        l60.q = junk.q;
    }
    l50.q = 0;
    if (src->quatp != 0) {
        l50.q = src->quatp->q;
    }
    if (src->w1C != 0) {
        l40.q = *(const u128 *)0x3F800000;
    } else {
        l40.q = 0;
    }
    q0 = src->quads[0];
    q1 = src->quads[1];
    q2 = src->quads[2];
    q3 = src->quads[3];
    dv = dst->vec;
    if (dv == 0) {
        dst->vec = &dst->buf30;
        dst->b2B = 1;
        dst->b29 = 1;
        dst->b2C = 0;
        dst->vec->q = l60.q;
        dst->b29 = 1;
    } else {
        if (dv->v.x != l60.v.x || dv->v.y != l60.v.y || dv->v.z != l60.v.z) {
            dv->q = l60.q;
            dst->b29 = 1;
        }
    }
    if (dst->quatp == 0) {
        dst->quatp = &dst->buf40;
        if (dst->quatp != 0) {
            if (dst->quatp->iw[3] == 0) {
                dst->quatp->iw[3] = 1;
            }
        }
        dst->b2B = 1;
        dst->b29 = 1;
        dst->b2C = 0;
        dst->quatp->iw[3] = 1;
        dst->quatp->q = l50.q;
        dst->b29 = 1;
    } else {
        if (dst->quatp->v.x != l50.v.x || dst->quatp->v.y != l50.v.y ||
            dst->quatp->v.z != l50.v.z) {
            dst->quatp->q = l50.q;
            dst->b29 = 1;
        }
    }
    if (dst->w1C != 0) {
        l50.q = *(const u128 *)0x3F800000;
    } else {
        l50.q = 0;
    }
    dst->quads[0] = q0;
    dst->quads[1] = q1;
    dst->quads[2] = q2;
    dst->quads[3] = q3;
    dst->b29 = 1;
}
