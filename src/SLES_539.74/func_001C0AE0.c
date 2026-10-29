// range: 0x1C0AE0 0x1C0B50
#include "common.h"

extern s32 func_001AC810(void *, s32);
extern M2C_UNK D_00411ED0 __attribute__((section(".data")));

typedef struct {
    /* 0x0 */ s32 isFloat;
    /* 0x4 */ union { s32 i; f32 f; } v;
    /* 0x8 */ s32 mode;
    /* 0xC */ union { s32 i; f32 f; s32 *p; } w;
} Val;

s32 func_001C0AE0(Val *arg0) {
    s32 t0;
    s32 r;

    if (arg0->isFloat == 1) {
        t0 = (s32)arg0->v.f;
    } else {
        t0 = arg0->v.i;
    }
    r = func_001AC810(&D_00411ED0, t0);
    if (arg0->mode == 3) {
        arg0->w.p[1] = r;
    }
    return 1;
}
