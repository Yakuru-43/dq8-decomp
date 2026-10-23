// range: 0x306120 0x306150
#include "common.h"

extern s32 D_003E1124;

s32 func_0014E240(s32, s32);

void func_00306120(s32 arg) {
    D_003E1124 = 0;
    if (arg == 0) {
        return;
    }
    D_003E1124 = func_0014E240(arg, 0x201);
}
