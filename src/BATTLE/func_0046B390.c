// range: 0x46B390 0x46B4A0
#include "common.h"

typedef struct TagArg {
    /* 0x00 */ s32 tag;
    /* 0x04 */ s32 bits;
} TagArg;

typedef struct NodeB390 {
    /* 0x00 */ TagArg a[7];
} NodeB390;

typedef union Vec4B390 {
    /* 0x00 */ u128 q;
    /* 0x00 */ f32 v[4];
} Vec4B390;

extern s32 D_003E1B9C;
extern s32 func_1A7A90(s32, f32 *, f32 *, s32);

s32 func_0046B390(NodeB390 *n) {
    Vec4B390 vecA;
    Vec4B390 vecB;
    TagArg *p;
    TagArg *q;
    TagArg *r;
    f32 x0;
    f32 x1;
    f32 x2;
    f32 x3;
    f32 x4;
    f32 x5;
    s32 i6;

    vecA.q = 0;
    vecB.q = 0;
    p = n->a;
    if (p[0].tag == 0) {
        x0 = (f32)p[0].bits;
    } else {
        x0 = *(f32 *)&p[0].bits;
    }
    vecA.v[0] = x0;
    q = p + 1;
    if (q->tag == 0) {
        x1 = (f32)q->bits;
    } else {
        x1 = *(f32 *)&q->bits;
    }
    vecA.v[1] = x1;
    if (p[2].tag == 0) {
        x2 = (f32)p[2].bits;
    } else {
        x2 = *(f32 *)&p[2].bits;
    }
    vecA.v[2] = x2;
    vecA.v[3] = 1.0f;
    q = p + 3;
    if (q->tag == 0) {
        x3 = (f32)q->bits;
    } else {
        x3 = *(f32 *)&q->bits;
    }
    vecB.v[0] = x3;
    r = q + 1;
    if (r->tag == 0) {
        x4 = (f32)r->bits;
    } else {
        x4 = *(f32 *)&r->bits;
    }
    vecB.v[1] = x4;
    if (q[2].tag == 0) {
        x5 = (f32)q[2].bits;
    } else {
        x5 = *(f32 *)&q[2].bits;
    }
    vecB.v[2] = x5;
    vecB.v[3] = 1.0f;
    if (p[6].tag == 1) {
        i6 = (s32)*(f32 *)&p[6].bits;
    } else {
        i6 = p[6].bits;
    }
    func_1A7A90(D_003E1B9C, vecA.v, vecB.v, i6);
    return 1;
}
