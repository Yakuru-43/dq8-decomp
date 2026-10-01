// range: 0x2072F0 0x207330
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_002072F0(s32 arg0, s32 arg1) {
    if ((arg1 >= 0) && (arg1 < 4)) {
        return arg0 + (arg1 * 0x30);
    }
    return 0;
}
