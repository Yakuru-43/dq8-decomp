// range: 0x2032E0 0x203310
// auto: m2c, verified byte-exact
#include "common.h"

s8 func_002032E0(s32 arg0, s32 arg1) {
    if ((arg1 >= 0) && (arg1 < 4)) {
        return M2C_FIELD((arg1 + arg0), s8 *, 0xA60);
    }
    return 0;
}
