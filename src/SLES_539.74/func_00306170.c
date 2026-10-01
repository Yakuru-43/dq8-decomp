// range: 0x306170 0x3061B0
// auto: m2c, verified byte-exact
#include "common.h"

void func_00306170(void *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = -1;
    M2C_FIELD(arg0, s32 *, 0xC) = -1;
    M2C_FIELD(arg0, s32 *, 8) = -1;
    M2C_FIELD(arg0, s32 *, 0x10) = 0x3F800000;
    M2C_FIELD(arg0, s32 *, 0x2C) = 0;
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0x3F800000;
    M2C_FIELD(arg0, s32 *, 0x24) = 0xBF800000;
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
}
