// range: 0x2F6300 0x2F6320
// auto: m2c, verified byte-exact
#include "common.h"

void func_002F6300(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    M2C_FIELD(arg0, s32 *, 0x15C) = arg1;
    M2C_FIELD(arg0, s32 *, 0x160) = arg2;
    M2C_FIELD(arg0, s32 *, 0x164) = arg3;
    M2C_FIELD(arg0, s32 *, 0x168) = arg4;
}
