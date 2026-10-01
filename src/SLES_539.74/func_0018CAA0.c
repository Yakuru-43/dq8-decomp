// range: 0x18CAA0 0x18CAD0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0018CAA0(s32 arg0, s32 arg1) {
    if ((arg1 >= 0) && (arg1 < 2)) {
        return arg0 + (arg1 * 8) + 0x5344;
    }
    return 0;
}
