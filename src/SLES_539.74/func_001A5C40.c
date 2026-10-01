// range: 0x1A5C40 0x1A5C50
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001A5C40(void *arg0, void *arg1) {
    M2C_FIELD(arg1, s32 *, 0x240) = (s32) M2C_FIELD(arg0, s32 *, 0x20);
    return 0;
}
