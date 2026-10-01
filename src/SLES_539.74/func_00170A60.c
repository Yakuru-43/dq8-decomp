// range: 0x170A60 0x170A80
// auto: m2c, verified byte-exact
#include "common.h"

void *func_00170A60(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = -1;
    M2C_FIELD(arg0, s32 *, 0xC) = 0xBF800000;
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    return arg0;
}
