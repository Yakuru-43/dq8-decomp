// range: 0x1D23B0 0x1D2400
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_001340C0(s32, M2C_UNK);                /* extern */

s32 func_001D23B0(s32 arg0, s32 arg1, M2C_UNK arg2) {
    if ((arg1 >= 0) && (arg1 < 8)) {
        func_001340C0(arg0 + (arg1 * 0x88) + 8, arg2);
        return 1;
    }
    return 0;
}
