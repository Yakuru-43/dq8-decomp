// range: 0x309870 0x3098A0
// auto: m2c, verified byte-exact
#include "common.h"

void func_00309870(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0) = 1;
    M2C_FIELD(arg0, s32 *, 4) = arg1;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = 0x3F800000;
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    M2C_FIELD(arg0, s16 *, 0x14) = 0;
}
