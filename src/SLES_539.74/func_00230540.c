// range: 0x230540 0x230580
// auto: m2c draft, verified byte-exact
#include "common.h"

char *func_00230540(char *arg0) {
    M2C_FIELD(arg0, s128 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, s128 *, 0x20) = 0;
    M2C_FIELD(arg0, s32 *, 0x40) = 0;
    M2C_FIELD(arg0, s32 *, 0x44) = 0x5A;
    M2C_FIELD(arg0, s32 *, 0x48) = 0xF;
    M2C_FIELD(arg0, s32 *, 0x4C) = 0x1E;
    return arg0;
}
