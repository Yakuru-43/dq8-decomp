// range: 0x0046B240 0x0046B390
#include "common.h"

extern s32 D_003E1B9C;
extern void func_1A7970(s32, f32 *, f32 *, s32, s32, f32);

struct Tagged {
    s32 tag;
    union {
        f32 f;
        s32 i;
    } u;
};

static inline f32 GetF(struct Tagged *t) {
    if (t->tag != 0) {
        return t->u.f;
    }
    return (f32)t->u.i;
}

static inline s32 GetI(struct Tagged *t) {
    if (t->tag == 1) {
        return (s32)t->u.f;
    }
    return t->u.i;
}

s32 func_0046B240(struct Tagged *p) {
    f32 a[4];
    f32 b[4];
    s32 x;
    s32 y;
    f32 z;

    a[0] = GetF(&p[0]);
    a[1] = GetF(&p[1]);
    a[2] = GetF(&p[2]);
    a[3] = 1.0f;
    b[0] = GetF(&p[3]);
    b[1] = GetF(&p[4]);
    b[2] = GetF(&p[5]);
    b[3] = 1.0f;
    x = GetI(&p[6]);
    y = GetI(&p[7]);
    z = GetF(&p[8]);
    func_1A7970(D_003E1B9C, a, b, x, y, z);
    return 1;
}
