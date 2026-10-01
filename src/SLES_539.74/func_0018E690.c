// range: 0x18E690 0x18E6E0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0018E6E0(s32);                             /* extern */
s32 func_0018E9F0(s32);                             /* extern */
s32 func_0018EA20();                                /* extern */

s32 func_0018E690(s32 arg0) {
    if (func_0018EA20() == 0) {
        if (func_0018E9F0(arg0) == 0) {
            return func_0018E6E0(arg0);
        }
        goto block_3;
    }
block_3:
    return 0;
}
