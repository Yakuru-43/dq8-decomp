// range: 0x305800 0x305830
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00167A80();                                /* extern */
s32 func_00371970(s32, M2C_UNK);                    /* extern */

s32 func_00305800(void) {
    return func_00371970(func_00167A80(), 2) == 0;
}
