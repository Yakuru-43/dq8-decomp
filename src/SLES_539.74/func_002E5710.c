// range: 0x2E5710 0x2E5720
// auto: m2c, verified byte-exact
#include "common.h"

void func_002E5710(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x1648) = arg1;
    M2C_FIELD(arg0, s32 *, 0x164C) = arg2;
}
