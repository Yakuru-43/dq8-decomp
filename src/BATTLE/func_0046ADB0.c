// range: 0x46ADB0 0x46AE80
#include "common.h"

typedef struct TagArg {
    /* 0x00 */ s32 tag;
    /* 0x04 */ s32 bits;
} TagArg;

typedef struct NodeADB0 {
    /* 0x00 */ TagArg a[6];
} NodeADB0;

extern s32 D_003E1B9C;
extern void func_1A6D40(s32, s32, s32, f32, f32, f32, f32);

s32 func_0046ADB0(NodeADB0 *n) {
    TagArg *p;
    TagArg *q;
    f32 x0;
    f32 x1;
    f32 x2;
    s32 i3;
    s32 i4;
    f32 x5;

    p = n->a;
    if (p[0].tag == 0) {
        x0 = (f32)p[0].bits;
    } else {
        x0 = *(f32 *)&p[0].bits;
    }
    q = p + 1;
    if (q->tag == 0) {
        x1 = (f32)q->bits;
    } else {
        x1 = *(f32 *)&q->bits;
    }
    q = p + 2;
    if (q->tag == 0) {
        x2 = (f32)q->bits;
    } else {
        x2 = *(f32 *)&q->bits;
    }
    q = p + 3;
    if (q->tag == 1) {
        i3 = (s32)*(f32 *)&q->bits;
    } else {
        i3 = q->bits;
    }
    q = p + 4;
    if (q->tag == 1) {
        i4 = (s32)*(f32 *)&q->bits;
    } else {
        i4 = q->bits;
    }
    if (p[5].tag == 0) {
        x5 = (f32)p[5].bits;
    } else {
        x5 = *(f32 *)&p[5].bits;
    }
    func_1A6D40(D_003E1B9C, i3, i4, x0, x1, x2, x5);
    return 1;
}
