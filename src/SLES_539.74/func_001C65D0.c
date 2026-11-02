// range: 0x1C65D0 0x1C66F0
#include "common.h"

extern void func_001A6360(s32, f32 *, s32, f32);
extern s32 D_003E06F4;
// pi / 256: the game's float literal, read-only, so its load may go above the frame save
extern const f32 D_003DF5B4 __attribute__((section(".sdata")));

typedef struct {
    /* 0x0 */ s32 isFloat;
    /* 0x4 */ union { s32 i; f32 f; } v;
} Tagged;

s32 func_001C65D0(Tagged *arg0, s32 arg1) {
    f32 vals[4];
    f32 val;
    s32 a2;
    f32 f;
    Tagged *p;

    vals[0] = 1.0f;
    vals[1] = 1.0f;
    vals[2] = 1.0f;
    vals[3] = 1.0f;
    val = D_003DF5B4;
    a2 = 0;
    switch (arg1) {
    case 1:
        a2 = (arg0[0].isFloat == 1) ? (s32)arg0[0].v.f : arg0[0].v.i;
        break;
    case 5:
        vals[0] = (arg0[0].isFloat == 0) ? (f32)arg0[0].v.i : arg0[0].v.f;
        p = arg0 + 1;
        if (p->isFloat == 0) {
            f = (f32)p->v.i;
        } else {
            f = p->v.f;
        }
        vals[1] = f;
        p = arg0 + 2;
        if (p->isFloat == 0) {
            f = (f32)p->v.i;
        } else {
            f = p->v.f;
        }
        vals[2] = f;
        p = arg0 + 3;
        if (p->isFloat == 0) {
            val = (f32)p->v.i;
        } else {
            val = p->v.f;
        }
        a2 = (arg0[4].isFloat == 1) ? (s32)arg0[4].v.f : arg0[4].v.i;
        break;
    }
    func_001A6360(D_003E06F4, vals, a2, val);
    return 1;
}
