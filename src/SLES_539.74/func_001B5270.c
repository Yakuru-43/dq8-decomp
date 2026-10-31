// range: 0x1B5270 0x1B5320
#include "common.h"

extern void func_00193520(void);
extern s32 func_00193560(void);
extern void func_00193570(s32 arg0);
extern s32 D_003E0664;

typedef struct {
    /* 0x0 */ s32 isFloat;
    /* 0x4 */ union { s32 i; f32 f; } v;
    /* 0x8 */ s32 mode;
    /* 0xC */ union { s32 i; f32 f; s32 *p; } w;
} Val;

s32 func_001B5270(Val *arg0) {
    s32 t0;
    s32 r;

    if (arg0->isFloat == 1) {
        t0 = (s32)arg0->v.f;
    } else {
        t0 = arg0->v.i;
    }
    switch (t0) {
    case 1:
        func_00193570(D_003E0664);
        break;
    case 2:
        r = func_00193560();
        if (arg0->mode == 3) {
            arg0->w.p[1] = r;
        }
        break;
    case 3:
        func_00193520();
        break;
    default:
        break;
    }
    return 1;
}
