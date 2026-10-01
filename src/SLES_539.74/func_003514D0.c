// range: 0x3514D0 0x3514E0
// auto: m2c, verified byte-exact
#include "common.h"

void func_003514D0(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x280) = arg1;
}
