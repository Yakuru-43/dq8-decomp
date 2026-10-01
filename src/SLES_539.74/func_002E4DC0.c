// range: 0x2E4DC0 0x2E4DE0
// auto: m2c, verified byte-exact
#include "common.h"

void func_002E4DC0(void *arg0, s16 arg1, s16 arg2) {
    M2C_FIELD(arg0, s8 *, 0x180) = 1;
    M2C_FIELD(arg0, s16 *, 0x17C) = arg1;
    M2C_FIELD(arg0, s8 *, 0x181) = 1;
    M2C_FIELD(arg0, s16 *, 0x17E) = arg2;
}
