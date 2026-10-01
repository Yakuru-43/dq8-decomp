// range: 0x1A8DD0 0x1A8DE0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001A8DD0(s32 arg0, void *arg1) {
    M2C_FIELD(arg1, s32 *, 0x94) = arg0;
    return 0;
}
