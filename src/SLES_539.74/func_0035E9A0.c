// range: 0x35E9A0 0x35E9F0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_001007A0();                            /* extern */

s32 func_0035E9A0(s32 arg0, s64 arg1) {
    if ((arg0 != 0) && (((s64) (arg1 << 0x30) >> 0x30) > 0)) {
        func_001007A0();
    }
    return arg0;
}
