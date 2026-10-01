// range: 0x356910 0x356920
// auto: m2c, verified byte-exact
#include "common.h"

void *func_00356910(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s8 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0) = arg1;
    return arg0;
}
