// range: 0x2C1800 0x2C1820
// auto: m2c, verified byte-exact
#include "common.h"

extern s32 D_0044F940 __attribute__((section(".data")));
extern s32 D_0044F944 __attribute__((section(".data")));
extern s32 D_0044F94C __attribute__((section(".data")));

void func_002C1800(void) {
    D_0044F940 = 0;
    D_0044F944 = 0;
    D_0044F94C = -1;
}
