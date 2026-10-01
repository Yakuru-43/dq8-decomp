// range: 0x2E61F0 0x2E6200
// auto: m2c, verified byte-exact
#include "common.h"

void func_002E61F0(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0xF0) = arg1;
    M2C_FIELD(arg0, s32 *, 0xF4) = arg2;
}
