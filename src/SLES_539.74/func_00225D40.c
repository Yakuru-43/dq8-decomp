// range: 0x225D40 0x225D50
// auto: m2c, verified byte-exact
#include "common.h"

void func_00225D40(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x10) = arg1;
    M2C_FIELD(arg0, s32 *, 0x14) = arg2;
}
