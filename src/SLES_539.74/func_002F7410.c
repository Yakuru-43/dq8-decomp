// range: 0x2F7410 0x2F7420
// auto: m2c, verified byte-exact
#include "common.h"

void func_002F7410(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x100) = arg1;
}
