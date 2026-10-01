// range: 0x370590 0x3705A0
// auto: m2c, verified byte-exact
#include "common.h"

void func_00370590(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x1C) = arg1;
}
