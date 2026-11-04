// range: 0x46A5D0 0x46A7D0
#include "common.h"

extern void func_1745A0(s32, s32, s32);
extern void func_174580(s32, s32, s32, s32);
extern void func_174560(s32, s32, s32, s32, s32);
extern s32 D_004219F0 __attribute__((section(".data")));

typedef struct {
    /* 0x0 */ s32 isFloat;
    /* 0x4 */ union { s32 i; f32 f; } v;
} Tagged;

s32 func_0046A5D0(Tagged *arg0, s32 arg1) {
    s32 v;
    s32 x1;
    s32 x2;
    s32 x3;
    s32 x4;
    Tagged *p;

    v = (arg0[0].isFloat == 1) ? (s32)arg0[0].v.f : arg0[0].v.i;
    if (v == -1) {
        v = D_004219F0;
    }
    switch (arg1) {
    case 2:
        x1 = (arg0[1].isFloat == 1) ? (s32)arg0[1].v.f : arg0[1].v.i;
        func_1745A0(v, x1, 0);
        return 1;
    case 3:
        p = arg0 + 1;
        if (p->isFloat == 1) {
            x1 = (s32)p->v.f;
        } else {
            x1 = p->v.i;
        }
        x2 = (arg0[2].isFloat == 1) ? (s32)arg0[2].v.f : arg0[2].v.i;
        func_1745A0(v, x1, x2);
        return 1;
    case 4:
        x1 = (arg0[1].isFloat == 1) ? (s32)arg0[1].v.f : arg0[1].v.i;
        p = arg0 + 2;
        if (p->isFloat == 1) {
            x2 = (s32)p->v.f;
        } else {
            x2 = p->v.i;
        }
        x3 = (arg0[3].isFloat == 1) ? (s32)arg0[3].v.f : arg0[3].v.i;
        func_174580(v, x1, x2, x3);
        return 1;
    case 5:
        x1 = (arg0[1].isFloat == 1) ? (s32)arg0[1].v.f : arg0[1].v.i;
        p = arg0 + 2;
        if (p->isFloat == 1) {
            x2 = (s32)p->v.f;
        } else {
            x2 = p->v.i;
        }
        p = arg0 + 3;
        if (p->isFloat == 1) {
            x3 = (s32)p->v.f;
        } else {
            x3 = p->v.i;
        }
        x4 = (arg0[4].isFloat == 1) ? (s32)arg0[4].v.f : arg0[4].v.i;
        func_174560(v, x1, x2, x3, x4);
        return 1;
    }
    return 1;
}
