// range: 0x349790 0x3497C0
// auto: m2c, verified byte-exact
#include "common.h"

void func_00349790(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    M2C_FIELD(arg0, s32 *, 0x3C) = 0x43700000;
    M2C_FIELD(arg0, s32 *, 0x40) = 0x43700000;
    M2C_FIELD(arg0, s8 *, 0x44) = 1;
    M2C_FIELD(arg0, s8 *, 0) = 0;
    M2C_FIELD(arg0, s8 *, 0x45) = 0;
    M2C_FIELD(arg0, s32 *, 0x34) = 0x3F800000;
}
