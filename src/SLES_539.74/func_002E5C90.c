// range: 0x2E5C90 0x2E5CA0
// auto: m2c, verified byte-exact
#include "common.h"

void func_002E5C90(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x1628) = arg1;
    M2C_FIELD(arg0, s32 *, 0x162C) = arg2;
}
