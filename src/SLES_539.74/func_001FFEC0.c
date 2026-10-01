// range: 0x1FFEC0 0x1FFED0
// auto: m2c, verified byte-exact
#include "common.h"

void func_001FFEC0(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x20) = arg1;
}
