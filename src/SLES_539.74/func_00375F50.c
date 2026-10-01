// range: 0x375F50 0x375F60
// auto: m2c, verified byte-exact
#include "common.h"

void func_00375F50(void *arg0, s16 arg1, s16 arg2) {
    M2C_FIELD(arg0, s16 *, 0x1C) = arg1;
    M2C_FIELD(arg0, s16 *, 0x1E) = arg2;
}
