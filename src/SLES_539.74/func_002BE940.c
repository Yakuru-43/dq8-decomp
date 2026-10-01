// range: 0x2BE940 0x2BE960
// auto: m2c, verified byte-exact
#include "common.h"

void func_002BE940(void *arg0, s16 arg1, s16 arg2) {
    M2C_FIELD(arg0, s16 *, 0x60) = arg1;
    M2C_FIELD(arg0, s16 *, 0x62) = arg2;
    M2C_FIELD(arg0, s32 *, 0x5C) = 0x3F000000;
}
