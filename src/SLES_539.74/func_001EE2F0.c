// range: 0x1EE2F0 0x1EE300
// auto: m2c, verified byte-exact
#include "common.h"

void func_001EE2F0(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x90) = arg1;
}
