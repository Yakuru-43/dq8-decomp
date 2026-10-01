// range: 0x2C1820 0x2C1850
// auto: m2c, verified byte-exact
#include "common.h"

void *func_002C1820(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0x2329;
    M2C_FIELD(arg0, s32 *, 4) = -1;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    return arg0;
}
