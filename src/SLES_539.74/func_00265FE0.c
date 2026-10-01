// range: 0x265FE0 0x266000
// auto: m2c, verified byte-exact
#include "common.h"

void func_00265FE0(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = 0x3F800000;
    M2C_FIELD(arg0, s32 *, 0x18) = 0xBF800000;
}
