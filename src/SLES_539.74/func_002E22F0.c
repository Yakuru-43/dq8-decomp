// range: 0x2E22F0 0x2E2310
// auto: m2c, verified byte-exact
#include "common.h"

void func_002E22F0(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x9C) = (s32) (arg1 + 0x16);
    M2C_FIELD(arg0, s32 *, 0xA0) = (s32) (arg2 + 0x1A);
}
