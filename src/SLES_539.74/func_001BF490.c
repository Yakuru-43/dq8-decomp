// range: 0x1BF490 0x1BF540
#include "common.h"

extern s32 func_002C20E0(char *);
extern void func_002C2100(char *);
extern void func_002C2180(char *);
extern char *D_003E0664;

typedef struct {
    /* 0x0 */ s32 isFloat;
    /* 0x4 */ union { s32 i; f32 f; } v;
    /* 0x8 */ s32 mode;
    /* 0xC */ union { s32 i; f32 f; s32 *p; } w;
} Val;

s32 func_001BF490(Val *arg0) {
    s32 t0;
    s32 r;

    if (arg0->isFloat == 1) {
        t0 = (s32)arg0->v.f;
    } else {
        t0 = arg0->v.i;
    }
    switch (t0) {
    case 0:
        func_002C2180(D_003E0664);
        break;
    case 1:
        func_002C2100(D_003E0664);
        break;
    case 2:
        r = func_002C20E0(D_003E0664);
        if (arg0->mode == 3) {
            arg0->w.p[1] = r;
        }
        break;
    default:
        break;
    }
    return 1;
}
