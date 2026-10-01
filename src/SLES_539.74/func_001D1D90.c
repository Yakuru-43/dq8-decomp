// range: 0x1D1D90 0x1D1DA0
// auto: m2c, verified byte-exact
#include "common.h"

void func_001D1D90(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x2C) = arg1;
}
