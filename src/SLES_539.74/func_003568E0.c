// range: 0x3568E0 0x3568F0
// auto: m2c, verified byte-exact
#include "common.h"

void *func_003568E0(void *arg0, s32 arg1, s8 arg2) {
    M2C_FIELD(arg0, s32 *, 0) = arg1;
    M2C_FIELD(arg0, s8 *, 4) = arg2;
    return arg0;
}
