// range: 0x32A180 0x32A190
// auto: m2c, verified byte-exact
#include "common.h"

void func_0032A180(void *arg0, s16 arg1, s16 arg2) {
    M2C_FIELD(arg0, s16 *, 0xC) = arg1;
    M2C_FIELD(arg0, s16 *, 0xE) = arg2;
}
