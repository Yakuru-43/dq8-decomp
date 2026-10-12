// range: 0x264AC0 0x264AE0
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_00264AC0(char *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0x3F800000;
    M2C_FIELD(arg0, s128 *, 0x10) = 0;
    M2C_FIELD(arg0, s32 *, 0x18) = 0x3F800000;
}
