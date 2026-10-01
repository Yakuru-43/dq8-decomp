// range: 0x202090 0x2020F0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00181420();                                /* extern */
s32 func_00205D30(s32, s32);                        /* extern */

s32 func_00202090(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < 4)) {
        return func_00205D30(func_00181420(), arg0);
    }
    return arg0;
}
