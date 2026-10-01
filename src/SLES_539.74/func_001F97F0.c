// range: 0x1F97F0 0x1F9800
// auto: m2c, verified byte-exact
#include "common.h"

void func_001F97F0(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x8C) = arg1;
}
