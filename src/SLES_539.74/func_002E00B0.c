// range: 0x2E00B0 0x2E00C0
// auto: m2c, verified byte-exact
#include "common.h"

void func_002E00B0(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x90) = arg1;
}
