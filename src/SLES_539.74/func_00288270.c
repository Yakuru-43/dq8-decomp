// range: 0x288270 0x288280
// auto: m2c, verified byte-exact
#include "common.h"

void func_00288270(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x454) = arg1;
}
