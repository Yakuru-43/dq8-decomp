// range: 0x2E22E0 0x2E22F0
// auto: m2c, verified byte-exact
#include "common.h"

void func_002E22E0(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x94) = arg1;
    M2C_FIELD(arg0, s32 *, 0x98) = arg2;
}
