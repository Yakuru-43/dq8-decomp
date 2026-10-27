// range: 0x1D1E00 0x1D1E20
// auto: m2c, verified byte-exact
#include "common.h"

void func_001D1E00(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    M2C_FIELD(arg0, s32 *, 0x5C) = arg1;
    M2C_FIELD(arg0, s32 *, 0x60) = arg2;
    M2C_FIELD(arg0, s32 *, 0x64) = arg3;
    M2C_FIELD(arg0, s32 *, 0x68) = arg4;
}
