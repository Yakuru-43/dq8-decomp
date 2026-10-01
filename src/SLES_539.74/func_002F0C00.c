// range: 0x2F0C00 0x2F0C10
// auto: m2c, verified byte-exact
#include "common.h"

void func_002F0C00(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x11CC) = arg1;
    M2C_FIELD(arg0, s32 *, 0x11D0) = arg2;
}
