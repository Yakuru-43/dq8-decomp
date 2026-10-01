// range: 0x164460 0x164470
// auto: m2c, verified byte-exact
#include "common.h"

void func_00164460(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x25C) = arg1;
}
