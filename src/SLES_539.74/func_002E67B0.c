// range: 0x2E67B0 0x2E67E0
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_002E67B0(s32 arg0, s32 arg1, s8 arg2) {

    if (!(arg1 >= 0)) {
        return;
    }

    if (arg1 >= 0x14) {
        return;
    }
    M2C_FIELD((arg1 + arg0), s8 *, 0x1784) = arg2;
}
