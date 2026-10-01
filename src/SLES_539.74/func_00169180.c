// range: 0x169180 0x1691D0
// auto: m2c, verified byte-exact
#include "common.h"

void *func_00169180(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 1;
    M2C_FIELD(arg0, s32 *, 4) = 0x3F800000;
    M2C_FIELD(arg0, f32 *, 8) = (f32) 0xBB8;
    M2C_FIELD(arg0, s32 *, 0xC) = 0x457A0000;
    M2C_FIELD(arg0, f32 *, 0x10) = (f32) 0x1388;
    return arg0;
}
