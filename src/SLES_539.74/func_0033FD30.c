// range: 0x33FD30 0x33FD70
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0014E920(s32, s32);                        /* extern */
s32 func_001667C0();                                /* extern */
extern s32 D_003E12C0;
extern s32 D_00453834 __attribute__((section(".data")));

s32 func_0033FD30(void) {
    s32 temp_v0;

    temp_v0 = func_0014E920(func_001667C0() * 8, D_003E12C0);
    D_00453834 = temp_v0;
    return temp_v0 != 0;
}
