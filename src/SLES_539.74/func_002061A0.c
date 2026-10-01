// range: 0x2061A0 0x2061F0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00205D30();                                /* extern */
s32 func_002061F0(s32, s32);                        /* extern */

s32 func_002061A0(s32 arg0, s32 arg1) {
    if ((arg1 >= 0) && (arg1 < 4)) {
        return func_002061F0(arg0, func_00205D30());
    }
    return 0;
}
