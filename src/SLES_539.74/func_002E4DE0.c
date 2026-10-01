// range: 0x2E4DE0 0x2E4DF0
// auto: m2c, verified byte-exact
#include "common.h"

void func_002E4DE0(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s8 *, 0x181) = 1;
    M2C_FIELD(arg0, s16 *, 0x17E) = arg1;
}
