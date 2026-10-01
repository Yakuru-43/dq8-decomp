// range: 0x2DE490 0x2DE4A0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_002DE490(void *arg0, s32 arg1) {
    return arg1 == M2C_FIELD(arg0, s8 *, 0x2A);
}
