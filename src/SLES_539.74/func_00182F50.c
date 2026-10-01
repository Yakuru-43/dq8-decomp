// range: 0x182F50 0x182F60
// auto: m2c, verified byte-exact
#include "common.h"

extern s32 D_0040F9B0 __attribute__((section(".data")));

s32 func_00182F50(void) {
    return D_0040F9B0 != 0;
}
