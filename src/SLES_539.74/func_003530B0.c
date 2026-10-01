// range: 0x3530B0 0x3530D0
// auto: m2c, verified byte-exact
#include "common.h"

extern s8 D_00453CA0 __attribute__((section(".data")));

s32 func_003530B0(void) {
    return D_00453CA0 == 1;
}
