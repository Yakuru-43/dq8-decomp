// range: 0x1C0A30 0x1C0AE0
#include "common.h"

extern s32 func_00168090(void);
extern void func_00376270(s32 arg0);

typedef struct {
    /* 0x0 */ s32 isFloat;
    /* 0x4 */ union { s32 i; f32 f; } v;
    /* 0x8 */ s32 mode;
    /* 0xC */ union { s32 i; f32 f; s32 *p; } w;
} Val;

s32 func_001C0A30(Val *arg0) {
    s32 t0;
    s32 val;
    s32 r;

    if (arg0->isFloat == 1) {
        t0 = (s32)arg0->v.f;
    } else {
        t0 = arg0->v.i;
    }
    switch (t0) {
    case 0:
        if (arg0->mode == 1) {
            val = (s32)arg0->w.f;
        } else {
            val = arg0->w.i;
        }
        func_00376270(val);
        break;
    case 1:
        r = func_00168090();
        if (arg0->mode == 3) {
            arg0->w.p[1] = r;
        }
        break;
    default:
        break;
    }
    return 1;
}
