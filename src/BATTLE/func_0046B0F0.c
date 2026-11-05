// range: 0x46B0F0 0x46B1A0
#include "common.h"

typedef struct TagArg {
    /* 0x00 */ s32 tag;
    /* 0x04 */ s32 bits;
} TagArg;

typedef struct NodeB0F0 {
    /* 0x00 */ TagArg a[4];
} NodeB0F0;

typedef union Vec4B0F0 {
    /* 0x00 */ u128 q;
    /* 0x00 */ f32 v[4];
} Vec4B0F0;

extern s32 D_003E1B9C;
extern void func_1A76B0(s32, f32 *, s32);

s32 func_0046B0F0(NodeB0F0 *n) {
    Vec4B0F0 vec;
    TagArg *p;
    f32 f;
    s32 i3;

    vec.q = 0;
    vec.v[0] = (n->a[0].tag == 0) ? (f32)n->a[0].bits : *(f32 *)&n->a[0].bits;
    p = n->a + 1;
    if (p->tag == 0) {
        f = (f32)p->bits;
    } else {
        f = *(f32 *)&p->bits;
    }
    vec.v[1] = f;
    p = n->a + 2;
    if (p->tag == 0) {
        f = (f32)p->bits;
    } else {
        f = *(f32 *)&p->bits;
    }
    vec.v[2] = f;
    vec.v[3] = 1.0f;
    i3 = (n->a[3].tag == 1) ? (s32)*(f32 *)&n->a[3].bits : n->a[3].bits;
    func_1A76B0(D_003E1B9C, vec.v, i3);
    return 1;
}
