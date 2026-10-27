// range: 0x1BE0A0 0x1BE170
#include "common.h"

extern char *func_001814D0(void);
extern s32 func_0024B930(s32, s32);
extern void func_0024B990(s32, s32, s32);

typedef struct {
    /* 0x0 */ s32 isFloat;
    /* 0x4 */ union { s32 i; f32 f; } v;
    /* 0x8 */ s32 mode;
    /* 0xC */ union { s32 i; f32 f; s32 *p; } w;
} Val;

s32 func_001BE0A0(Val *arg0) {
    s32 t0;
    s32 val;
    s32 r;

    if (arg0->isFloat == 1) {
        t0 = (s32)arg0->v.f;
    } else {
        t0 = arg0->v.i;
    }
    switch (arg0->mode) {
    case 0:
        if (arg0->mode == 1) {
            val = (s32)arg0->w.f;
        } else {
            val = arg0->w.i;
        }
        func_0024B990((s32)func_001814D0() + 0x59D0, t0, val);
        break;
    case 3:
        r = func_0024B930((s32)func_001814D0() + 0x59D0, t0);
        if (arg0->mode == 3) {
            arg0->w.p[1] = r;
        }
        break;
    default:
        break;
    }
    return 1;
}
