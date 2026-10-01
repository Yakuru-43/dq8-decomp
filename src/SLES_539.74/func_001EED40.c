// range: 0x1EED40 0x1EED50
// auto: m2c, verified byte-exact
#include "common.h"

void func_001EED40(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x10) = arg1;
}
