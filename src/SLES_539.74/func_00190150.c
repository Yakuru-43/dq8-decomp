// range: 0x190150 0x190160
// auto: m2c, verified byte-exact
#include "common.h"

void func_00190150(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x44BC) = arg1;
}
