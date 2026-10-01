// range: 0x200000 0x200010
// auto: m2c, verified byte-exact
#include "common.h"

void func_00200000(void *arg0) {
    M2C_FIELD(arg0, s8 *, 1) = 0;
}
