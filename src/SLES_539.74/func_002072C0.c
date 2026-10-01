// range: 0x2072C0 0x2072F0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_002072C0(s32 arg0, s32 arg1) {
    if ((arg1 >= 0) && (arg1 < 0x18C)) {
        return arg0 + (arg1 * 4) + 0xC0;
    }
    return 0;
}
