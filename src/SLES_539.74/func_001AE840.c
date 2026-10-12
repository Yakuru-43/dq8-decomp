// range: 0x1AE840 0x1AE880
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_001AE840(char *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    M2C_FIELD(arg0, s128 *, 0x10) = 0;
    M2C_FIELD(arg0, s32 *, 0x20) = 0xBF800000;
    M2C_FIELD(arg0, s32 *, 0x28) = 0;
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
    M2C_FIELD(arg0, s32 *, 0x2C) = 1;
    M2C_FIELD(arg0, s32 *, 0x30) = 3;
}
