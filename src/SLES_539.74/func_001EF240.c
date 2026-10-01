// range: 0x1EF240 0x1EF250
// auto: m2c, verified byte-exact
#include "common.h"

void func_001EF240(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x10) = arg1;
}
