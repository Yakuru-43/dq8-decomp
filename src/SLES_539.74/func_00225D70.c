// range: 0x225D70 0x225D80
// auto: m2c, verified byte-exact
#include "common.h"

void func_00225D70(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x1F28) = arg1;
}
