// range: 0x2F5F80 0x2F5F90
// auto: m2c, verified byte-exact
#include "common.h"

void func_002F5F80(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x1614) = arg1;
}
