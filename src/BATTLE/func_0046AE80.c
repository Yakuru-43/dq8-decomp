// range: 0x46AE80 0x46AF10
#include "common.h"

typedef struct TagArg {
    /* 0x00 */ s32 tag;
    /* 0x04 */ s32 bits;
} TagArg;

typedef struct NodeAE80 {
    /* 0x00 */ TagArg a[4];
} NodeAE80;

extern s32 D_003E1B9C;
extern void func_1A6E10(s32, s32, f32, f32, f32);

s32 func_0046AE80(NodeAE80 *n) {
    TagArg *p;
    TagArg *q;
    f32 x0;
    f32 x1;
    f32 x2;
    s32 i3;

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
    if (p[3].tag == 1) {
        i3 = (s32)*(f32 *)&p[3].bits;
    } else {
        i3 = p[3].bits;
    }
    func_1A6E10(D_003E1B9C, i3, x0, x1, x2);
    return 1;
}
