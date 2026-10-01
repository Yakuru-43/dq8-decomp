// range: 0x313870 0x3138C0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_001629F0();                                /* extern */
s32 func_001632D0();                                /* extern */

s32 func_00313870(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg3 != 0) {
        if (func_001632D0() == 0) {
            return 0;
        }
        goto block_5;
    }
    if (func_001629F0() == 0) {
        return 0;
    }
block_5:
    return 1;
}
