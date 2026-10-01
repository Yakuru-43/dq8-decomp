// range: 0x188580 0x188590
// auto: m2c, verified byte-exact
#include "common.h"

void func_00188580(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x6B50) = arg1;
    M2C_FIELD(arg0, s32 *, 0x6B54) = arg2;
}
