// range: 0x361CA0 0x361CE0
// auto: m2c, verified byte-exact
#include "common.h"

void *func_00361CA0(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = -1;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
    M2C_FIELD(arg0, s16 *, 0x10) = 0;
    M2C_FIELD(arg0, s16 *, 0x12) = 0;
    M2C_FIELD(arg0, s16 *, 0x14) = 0x200;
    M2C_FIELD(arg0, s16 *, 0x16) = 0x1C0;
    M2C_FIELD(arg0, s16 *, 0x18) = 0;
    return arg0;
}
