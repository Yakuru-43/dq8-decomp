// range: 0x200D60 0x200D70
// auto: m2c, verified byte-exact
#include "common.h"

void func_00200D60(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0xC) = arg1;
}
