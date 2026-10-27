// range: 0x1B5570 0x1B5600
#include "common.h"

extern s32 D_003E0664;
extern void func_002BE1B0(s32, s32, s32);

s32 func_001B5570(char *arg0) {
    s32 s0;
    s32 v1;

    v1 = *(s32 *)arg0;
    if (v1 == 1) {
        s0 = (s32)*(f32 *)(arg0 + 4);
    } else {
        s0 = *(s32 *)(arg0 + 4);
    }

    if (s0 >= 0 && s0 < 5) {
        func_002BE1B0(D_003E0664, s0, 0);
        func_002BE1B0(D_003E0664, s0, 1);
        func_002BE1B0(D_003E0664, s0, 2);
        return 1;
    }
    return 0;
}
