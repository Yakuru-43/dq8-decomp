// range: 0x16BEF0 0x16BF30
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0016BEF0(s32 arg0, s32 arg1) {
    if ((arg1 >= 0) && (arg1 < 0xE)) {
        return arg0 + (arg1 * 0x58) + 0x38;
    }
    return 0;
}
