// range: 0x372BC0 0x372BD0
// auto: m2c, verified byte-exact
#include "common.h"

void func_00372BC0(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 4) = arg1;
    M2C_FIELD(arg0, s32 *, 8) = arg2;
}
