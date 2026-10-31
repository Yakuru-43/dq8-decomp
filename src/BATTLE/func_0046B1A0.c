// range: 0x46B1A0 0x46B240
#include "common.h"

typedef struct TagArg {
    /* 0x00 */ s32 tag;
    /* 0x04 */ s32 bits;
} TagArg;

typedef struct NodeB1A0 {
    /* 0x00 */ TagArg a[4];
} NodeB1A0;

typedef union Vec4B1A0 {
    /* 0x00 */ u128 q;
    /* 0x00 */ f32 v[4];
} Vec4B1A0;

extern s32 D_003E1B9C;
extern void func_1A7890(s32, f32 *, s32);

s32 func_0046B1A0(NodeB1A0 *n) {
    Vec4B1A0 vec;
    TagArg *p;
    TagArg *q;
    f32 x0;
    f32 x1;
    f32 x2;
    s32 i3;

    vec.q = 0;
    p = n->a;
    if (p[0].tag == 0) {
        x0 = (f32)p[0].bits;
    } else {
        x0 = *(f32 *)&p[0].bits;
    }
    vec.v[0] = x0;
    q = p + 1;
    if (q->tag == 0) {
        x1 = (f32)q->bits;
    } else {
        x1 = *(f32 *)&q->bits;
    }
    vec.v[1] = x1;
    if (p[2].tag == 0) {
        x2 = (f32)p[2].bits;
    } else {
        x2 = *(f32 *)&p[2].bits;
    }
    vec.v[2] = x2;
    vec.v[3] = 1.0f;
    if (p[3].tag == 1) {
        i3 = (s32)*(f32 *)&p[3].bits;
    } else {
        i3 = p[3].bits;
    }
    func_1A7890(D_003E1B9C, vec.v, i3);
    return 1;
}
