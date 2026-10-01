// range: 0x225D50 0x225D60
// auto: m2c, verified byte-exact
#include "common.h"

void func_00225D50(void *arg0, s16 arg1, s16 arg2) {
    M2C_FIELD(arg0, s16 *, 0xA) = arg1;
    M2C_FIELD(arg0, s16 *, 0xC) = arg2;
}
