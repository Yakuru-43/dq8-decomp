// range: 0x470D50 0x470E40
#include "common.h"

extern s32 func_18E940(s32);
extern s32 func_18F130(s32);
extern s32 func_192170(void);

typedef struct {
    /* 0x0 */ s32 isFloat;
    /* 0x4 */ union { s32 i; f32 f; } v;
    /* 0x8 */ s32 mode;
    /* 0xC */ union { s32 i; s32 *p; } w;
    /* 0x10 */ s32 mode2;
    /* 0x14 */ s32 *p2;
} S_arg0;

s32 func_00470D50(S_arg0 *arg0) {
    s32 s2;
    s32 s0;
    s32 v0;

    if (arg0->isFloat == 1) {
        s2 = (s32)arg0->v.f;
    } else {
        s2 = arg0->v.i;
    }

    s0 = func_192170();
    v0 = func_18E940(s0);

    switch (s2) {
    case 0:
        if (arg0->mode == 3) {
            arg0->w.p[1] = s0;
        }
        break;
    case 1:
        if (arg0->mode == 3) {
            arg0->w.p[1] = v0;
        }
        break;
    case 2:
        s2 = 0;
        if (s0 == func_18F130(arg0->w.i)) {
            s2 = 1;
        }
        if (arg0->mode2 == 3) {
            arg0->p2[1] = s2;
        }
        break;
    }

    return 1;
}
