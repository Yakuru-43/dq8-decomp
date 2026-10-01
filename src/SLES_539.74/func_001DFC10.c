// range: 0x1DFC10 0x1DFC40
// auto: m2c, verified byte-exact
#include "common.h"

void *func_001DFC10(void *arg0) {
    M2C_FIELD(arg0, s8 *, 8) = 0;
    M2C_FIELD(arg0, s8 *, 0x28) = 0;
    M2C_FIELD(arg0, s8 *, 0x48) = 0;
    M2C_FIELD(arg0, s32 *, 0x68) = 0;
    M2C_FIELD(arg0, s32 *, 0) = 1;
    M2C_FIELD(arg0, s32 *, 0x6C) = 0;
    return arg0;
}
