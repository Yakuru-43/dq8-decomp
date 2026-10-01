// range: 0x2827B0 0x2827F0
// auto: m2c, verified byte-exact
#include "common.h"

extern M2C_UNK D_003DE980 __attribute__((section(".data")));

void *func_002827B0(void *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x24) = &D_003DE980;
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0xBF800000;
    M2C_FIELD(arg0, s32 *, 0x20) = 0xBF800000;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s8 *, 0x10) = 0;
    return arg0;
}
