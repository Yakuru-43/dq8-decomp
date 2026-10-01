// range: 0x2DB560 0x2DB5A0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_002DB560(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg0 < 0) {
        return 0;
    }
    if ((arg0 == 0) && (arg1 == 0) && (arg2 == 0) && (arg3 == 0)) {
        return 0;
    }
    return 1;
}
