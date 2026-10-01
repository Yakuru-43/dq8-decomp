// range: 0x3838B0 0x383900
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_002C17B0();                                /* extern */
s32 func_002C17F0();                                /* extern */

s32 func_003838B0(void) {
    if (func_002C17F0() == 0) {
        goto block_1;
    }
    if (func_002C17B0() == 0x234B) {
        return 1;
    }
block_1:
    return 0;
}
