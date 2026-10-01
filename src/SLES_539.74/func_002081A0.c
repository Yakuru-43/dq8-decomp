// range: 0x2081A0 0x2081E0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_002081A0(s32 arg0, s32 arg1) {
    if ((arg1 >= 0) && (arg1 < 2)) {
        return arg0 + (arg1 * 0x6C) + 0x5790;
    }
    return 0;
}
