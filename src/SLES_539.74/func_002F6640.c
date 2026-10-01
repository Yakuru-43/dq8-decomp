// range: 0x2F6640 0x2F6650
// auto: m2c, verified byte-exact
#include "common.h"

void func_002F6640(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x1F14) = arg1;
}
