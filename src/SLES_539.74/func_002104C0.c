// range: 0x2104C0 0x210500
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_002104C0(s32 arg0, s32 arg1) {
    if ((arg1 >= 0) && (arg1 < 0x1E)) {
        return arg0 + (arg1 * 0x50) + 0x6BF0;
    }
    return 0;
}
