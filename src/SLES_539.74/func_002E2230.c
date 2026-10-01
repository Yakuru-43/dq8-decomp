// range: 0x2E2230 0x2E2240
// auto: m2c, verified byte-exact
#include "common.h"

void func_002E2230(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x80) = arg1;
}
