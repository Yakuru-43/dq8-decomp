// range: 0x13FC30 0x13FC60
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0013FC30(s32 arg0, s32 arg1) {
    if ((arg1 >= 0) && (arg1 < 4)) {
        return arg0 + (arg1 * 0x10) + 0x3CC0;
    }
    return 0;
}
