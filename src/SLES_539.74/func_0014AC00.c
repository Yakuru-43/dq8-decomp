// range: 0x14AC00 0x14AC20
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_0014AC00(char *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x14) = arg1;
    M2C_FIELD(arg0, s8 *, 0x2B) = 1;
    M2C_FIELD(arg0, s8 *, 0x29) = 1;
}
