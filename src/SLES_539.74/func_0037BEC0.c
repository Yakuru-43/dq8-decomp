// range: 0x37BEC0 0x37BEF0
// auto: m2c, verified byte-exact
#include "common.h"

void func_0037BEC0(s32 arg0, s32 arg1, s8 arg2) {
    if ((arg1 >= 0) && (arg1 < 4)) {
        M2C_FIELD((arg1 + arg0), s8 *, 0x10) = arg2;
    }
}
