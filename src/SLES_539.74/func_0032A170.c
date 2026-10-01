// range: 0x32A170 0x32A180
// auto: m2c, verified byte-exact
#include "common.h"

void func_0032A170(void *arg0, s16 arg1, s16 arg2) {
    M2C_FIELD(arg0, s16 *, 0x10) = arg1;
    M2C_FIELD(arg0, s16 *, 0x12) = arg2;
}
