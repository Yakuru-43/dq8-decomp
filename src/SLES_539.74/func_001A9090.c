// range: 0x1A9090 0x1A90A0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001A9090(s32 arg0, void *arg1) {
    M2C_FIELD(arg1, s32 *, 0x98) = arg0;
    return 0;
}
