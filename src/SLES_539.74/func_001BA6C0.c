// range: 0x1BA6C0 0x1BA6D0
// auto: m2c, verified byte-exact
#include "common.h"

extern s32 D_00411E6C __attribute__((section(".data")));

s32 func_001BA6C0(void) {
    D_00411E6C = 0;
    return 1;
}
