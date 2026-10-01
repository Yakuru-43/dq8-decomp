// range: 0x1D5BD0 0x1D5BE0
// auto: m2c, verified byte-exact
#include "common.h"

void func_001D5BD0(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 8) = arg1;
    M2C_FIELD(arg0, s32 *, 4) = arg2;
}
