// range: 0x2DB550 0x2DB560
// auto: m2c, verified byte-exact
#include "common.h"

void func_002DB550(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0xB9) = arg1;
}
