// range: 0x201F10 0x201F70
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00181420();                                /* extern */
s32 func_00205250(s32, s32);                        /* extern */

s32 func_00201F10(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < 4)) {
        return func_00205250(func_00181420(), arg0);
    }
    return 0;
}
