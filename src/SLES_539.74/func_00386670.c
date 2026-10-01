// range: 0x386670 0x386680
// auto: m2c, verified byte-exact
#include "common.h"

void func_00386670(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x46) = arg1;
    M2C_FIELD(arg0, s8 *, 0x47) = 1;
}
