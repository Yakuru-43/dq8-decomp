// range: 0x166220 0x166230
// auto: m2c, verified byte-exact
#include "common.h"

void func_00166220(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x30) = arg1;
}
