// range: 0x46B4A0 0x46B510
#include "common.h"

typedef struct TagArg {
    /* 0x00 */ s32 tag;
    /* 0x04 */ s32 bits;
} TagArg;

extern s32 D_003E1B9C;
extern void func_1A6ED0(s32, f32, f32, f32);

s32 func_0046B4A0(TagArg *p) {
    TagArg *q;
    f32 x0;
    f32 x1;
    f32 x2;

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
    if (p[2].tag == 0) {
        x2 = (f32)p[2].bits;
    } else {
        x2 = *(f32 *)&p[2].bits;
    }
    func_1A6ED0(D_003E1B9C, x0, x1, x2);
    return 1;
}
