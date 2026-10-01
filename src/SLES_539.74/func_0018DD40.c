// range: 0x18DD40 0x18DD70
// auto: m2c, verified byte-exact
#include "common.h"

void func_0018DD40(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0x40C00000;
    M2C_FIELD(arg0, s32 *, 4) = 0x41100000;
    M2C_FIELD(arg0, s32 *, 8) = 0x41880000;
    M2C_FIELD(arg0, s32 *, 0xC) = 0x41980000;
    M2C_FIELD(arg0, s32 *, 0x10) = 0x3F800000;
    M2C_FIELD(arg0, s8 *, 0x14) = 0;
}
