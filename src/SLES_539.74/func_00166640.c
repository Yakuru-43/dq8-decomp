// range: 0x166640 0x166650
// auto: m2c, verified byte-exact
#include "common.h"

void func_00166640(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x14) = arg1;
    M2C_FIELD(arg0, s32 *, 0x10) = arg2;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
}
