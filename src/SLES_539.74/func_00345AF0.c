// range: 0x345AF0 0x345B00
// auto: m2c, verified byte-exact
#include "common.h"

void func_00345AF0(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x1DC) = arg1;
}
