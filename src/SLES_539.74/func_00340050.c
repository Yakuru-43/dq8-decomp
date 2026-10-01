// range: 0x340050 0x340090
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0014E920(s32, s32);                        /* extern */
s32 func_001667C0();                                /* extern */
extern s32 D_003E12B8;
extern s32 D_004537D4 __attribute__((section(".data")));

s32 func_00340050(void) {
    s32 temp_v0;

    temp_v0 = func_0014E920(func_001667C0() * 0xC, D_003E12B8);
    D_004537D4 = temp_v0;
    return temp_v0 != 0;
}
