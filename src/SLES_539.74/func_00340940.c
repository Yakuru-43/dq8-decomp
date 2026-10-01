// range: 0x340940 0x340960
// auto: m2c, verified byte-exact
#include "common.h"

void func_00340940(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 1;
    M2C_FIELD(arg0, s32 *, 8) = 1;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
    M2C_FIELD(arg0, s32 *, 0x10) = 1;
}
