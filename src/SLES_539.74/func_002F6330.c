// range: 0x2F6330 0x2F6340
// auto: m2c, verified byte-exact
#include "common.h"

void func_002F6330(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x15A) = arg1;
}
