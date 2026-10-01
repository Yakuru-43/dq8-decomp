// range: 0x203310 0x203340
// auto: m2c, verified byte-exact
#include "common.h"

void func_00203310(s32 arg0, s32 arg1, s8 arg2) {
    if ((arg1 >= 0) && (arg1 < 4)) {
        M2C_FIELD((arg1 + arg0), s8 *, 0xA60) = arg2;
    }
}
