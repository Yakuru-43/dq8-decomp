// range: 0x2B0CC0 0x2B0CF0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_002B0CC0(s32 arg0, s32 arg1) {
    if ((arg1 >= 0) && (arg1 < 2)) {
        return arg0 + (arg1 << 5);
    }
    return 0;
}
