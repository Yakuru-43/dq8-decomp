// range: 0x222300 0x222310
// auto: m2c, verified byte-exact
#include "common.h"

void func_00222300(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x20) = arg1;
}
