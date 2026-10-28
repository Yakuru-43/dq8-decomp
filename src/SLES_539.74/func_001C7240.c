// range: 0x1C7240 0x1C72F0
#include "common.h"

extern s32 func_001A76B0(char *arg0, f32 *arg1, s32 arg2);
extern char *D_003E06F4;

typedef struct {
    /* 0x0 */ s32 isFloat;
    /* 0x4 */ union { s32 i; f32 f; } v;
} Tagged;

typedef union {
    f32 f[4];
    u128 q;
} ArgBuf;

s32 func_001C7240(Tagged *arg0) {
    ArgBuf args;
    f32 f1;
    f32 f2;
    f32 f3;
    s32 n;
    Tagged *t1;
    Tagged *t2;

    args.q = 0;
    if (arg0[0].isFloat == 0) {
        f1 = (f32)arg0[0].v.i;
    } else {
        f1 = arg0[0].v.f;
    }
    args.f[0] = f1;
    t1 = arg0 + 1;
    if (t1->isFloat == 0) {
        f2 = (f32)t1->v.i;
    } else {
        f2 = t1->v.f;
    }
    args.f[1] = f2;
    t2 = arg0 + 2;
    if (t2->isFloat == 0) {
        f3 = (f32)t2->v.i;
    } else {
        f3 = t2->v.f;
    }
    args.f[3] = 1.0f;
    args.f[2] = f3;
    if (arg0[3].isFloat == 1) {
        n = (s32)arg0[3].v.f;
    } else {
        n = arg0[3].v.i;
    }
    func_001A76B0(D_003E06F4, args.f, n);
    return 1;
}
