// range: 0x166650 0x166670
// auto: m2c, verified byte-exact
#include "common.h"

void func_00166650(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x20) = arg1;
    M2C_FIELD(arg0, s32 *, 0x18) = arg2;
    M2C_FIELD(arg0, s32 *, 0x1C) = (s32) M2C_FIELD(arg0, s32 *, 0x20);
}
