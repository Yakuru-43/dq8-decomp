// range: 0x340220 0x340260
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0014E920(s32, s32);                        /* extern */
s32 func_001667C0();                                /* extern */
extern s32 D_003E12B4;
extern s32 D_004537A4 __attribute__((section(".data")));

s32 func_00340220(void) {
    s32 temp_v0;

    temp_v0 = func_0014E920(func_001667C0() * 8, D_003E12B4);
    D_004537A4 = temp_v0;
    return temp_v0 != 0;
}
