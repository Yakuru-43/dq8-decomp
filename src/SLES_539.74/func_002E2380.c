// range: 0x2E2380 0x2E23A0
// auto: m2c, verified byte-exact
#include "common.h"

void func_002E2380(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    M2C_FIELD(arg0, u8 *, 0xA6) = 1;
    M2C_FIELD(arg0, s32 *, 0xA8) = arg1;
    M2C_FIELD(arg0, s32 *, 0xAC) = arg2;
    M2C_FIELD(arg0, s32 *, 0xB0) = arg3;
    M2C_FIELD(arg0, s32 *, 0xB4) = arg4;
}
