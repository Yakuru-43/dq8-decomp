// range: 0x2C17D0 0x2C17F0
// auto: m2c, verified byte-exact
#include "common.h"

extern s32 D_0044F944 __attribute__((section(".data")));

s32 func_002C17D0(void) {
    s32 temp_v0;

    temp_v0 = D_0044F944;
    D_0044F944 = 0;
    return temp_v0;
}
