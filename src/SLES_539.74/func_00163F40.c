// range: 0x163F40 0x163F70
// auto: m2c, verified byte-exact
#include "common.h"

void *func_00163F40(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 0;
    M2C_FIELD(arg0, s8 *, 2) = 0;
    M2C_FIELD(arg0, s8 *, 1) = 0;
    M2C_FIELD(arg0, s8 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 0x6C) = 0;
    M2C_FIELD(arg0, s32 *, 0x70) = 1;
    M2C_FIELD(arg0, s8 *, 0x78) = 0;
    return arg0;
}
