// range: 0x2E6500 0x2E6520
// auto: m2c, verified byte-exact
#include "common.h"

void func_002E6500(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    M2C_FIELD(arg0, u8 *, 0x166C) = 2;
    M2C_FIELD(arg0, s32 *, 0x1670) = arg1;
    M2C_FIELD(arg0, s32 *, 0x1674) = arg2;
    M2C_FIELD(arg0, s32 *, 0x1678) = arg3;
    M2C_FIELD(arg0, s32 *, 0x167C) = arg4;
}
