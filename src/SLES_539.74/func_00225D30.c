// range: 0x225D30 0x225D40
// auto: m2c, verified byte-exact
#include "common.h"

void func_00225D30(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x18) = arg1;
    M2C_FIELD(arg0, s32 *, 0x1C) = arg2;
}
