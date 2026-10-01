// range: 0x164050 0x164060
// auto: m2c, verified byte-exact
#include "common.h"

void func_00164050(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x258) = arg1;
}
