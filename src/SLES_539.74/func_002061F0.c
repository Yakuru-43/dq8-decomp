// range: 0x2061F0 0x206230
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_002061F0(s32 arg0, s32 arg1) {
    if ((arg1 >= 0) && (arg1 < 4)) {
        return arg0 + (arg1 * 0x68) + 0x40;
    }
    return 0;
}
