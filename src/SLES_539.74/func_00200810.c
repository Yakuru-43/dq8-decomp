// range: 0x200810 0x200820
// auto: m2c, verified byte-exact
#include "common.h"

void func_00200810(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x690C) = arg1;
    M2C_FIELD(arg0, s32 *, 0x6910) = 0;
    M2C_FIELD(arg0, s32 *, 0x6914) = 0;
}
