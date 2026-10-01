// range: 0x220EF0 0x220F00
// auto: m2c, verified byte-exact
#include "common.h"

void func_00220EF0(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x1F38) = arg1;
}
