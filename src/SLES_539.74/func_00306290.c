// range: 0x306290 0x3062B0
// auto: m2c, verified byte-exact
#include "common.h"

void func_00306290(void *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0) = 0x3F800000;
    M2C_FIELD(arg0, s32 *, 8) = 0xBF800000;
}
