// range: 0x144620 0x144640
// auto: m2c, verified byte-exact
#include "common.h"

void func_00144620(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0xF08) = arg1;
    M2C_FIELD(arg0, s32 *, 0xF0C) = arg2;
    M2C_FIELD(arg0, s32 *, 0xF14) = 1;
}
