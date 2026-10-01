// range: 0x2E5800 0x2E5810
// auto: m2c, verified byte-exact
#include "common.h"

void func_002E5800(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x1640) = arg1;
    M2C_FIELD(arg0, s32 *, 0x1644) = arg2;
}
