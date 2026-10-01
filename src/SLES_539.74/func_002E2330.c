// range: 0x2E2330 0x2E2340
// auto: m2c, verified byte-exact
#include "common.h"

void func_002E2330(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x9C) = arg1;
    M2C_FIELD(arg0, s32 *, 0xA0) = arg2;
}
