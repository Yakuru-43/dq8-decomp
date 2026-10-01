// range: 0x1D1E20 0x1D1E30
// auto: m2c, verified byte-exact
#include "common.h"

void func_001D1E20(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x54) = arg1;
    M2C_FIELD(arg0, s32 *, 0x58) = arg2;
}
