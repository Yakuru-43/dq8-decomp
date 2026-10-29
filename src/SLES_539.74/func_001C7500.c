// range: 0x1C7500 0x1C7620
#include "common.h"

extern s32 func_001A7A90(s32, f32 *, f32 *, s32);
extern s32 D_003E06F4;

typedef struct {
    /* 0x0 */ s32 isFloat;
    /* 0x4 */ union { s32 i; f32 f; } v;
} Tagged;

typedef union {
    f32 f[4];
    u128 q;
} ArgBuf;

s32 func_001C7500(Tagged *arg0) {
    ArgBuf args1;
    ArgBuf args2;
    f32 f1;
    f32 f2;
    f32 f3;
    f32 f4;
    f32 f5;
    f32 f6;
    s32 n;
    Tagged *t1;
    Tagged *t2;
    Tagged *t3;
    Tagged *t4;
    Tagged *t5;

    args1.q = 0;
    args2.q = 0;

    if (arg0[0].isFloat == 0) {
        f1 = (f32)arg0[0].v.i;
    } else {
        f1 = arg0[0].v.f;
    }
    args1.f[0] = f1;

    t1 = arg0 + 1;
    if (t1->isFloat == 0) {
        f2 = (f32)t1->v.i;
    } else {
        f2 = t1->v.f;
    }
    args1.f[1] = f2;

    t2 = arg0 + 2;
    if (t2->isFloat == 0) {
        f3 = (f32)t2->v.i;
    } else {
        f3 = t2->v.f;
    }
    args1.f[2] = f3;
    args1.f[3] = 1.0f;

    t3 = arg0 + 3;
    if (t3->isFloat == 0) {
        f4 = (f32)t3->v.i;
    } else {
        f4 = t3->v.f;
    }
    args2.f[0] = f4;

    t4 = arg0 + 4;
    if (t4->isFloat == 0) {
        f5 = (f32)t4->v.i;
    } else {
        f5 = t4->v.f;
    }
    args2.f[1] = f5;

    t5 = arg0 + 5;
    if (t5->isFloat == 0) {
        f6 = (f32)t5->v.i;
    } else {
        f6 = t5->v.f;
    }
    args2.f[2] = f6;
    args2.f[3] = 1.0f;

    if (arg0[6].isFloat == 1) {
        n = (s32)arg0[6].v.f;
    } else {
        n = arg0[6].v.i;
    }

    func_001A7A90(D_003E06F4, args1.f, args2.f, n);
    return 1;
}
