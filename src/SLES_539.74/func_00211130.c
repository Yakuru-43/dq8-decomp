// range: 0x211130 0x2111A0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0018E9B0(s32);                             /* extern */
s32 func_0018EA80();                                /* extern */
s32 func_0033E6A0();                                /* extern */
s32 func_00345E80();                                /* extern */

s32 func_00211130(s32 arg0) {
    if (func_0018EA80() != 0) {
        goto block_1;
    }
    if ((func_0033E6A0() == 0) && (func_00345E80() == 0) && (func_0018E9B0(arg0) == 0)) {
        return 0;
    }
block_1:
    return 1;
}
