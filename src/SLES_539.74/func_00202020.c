// range: 0x202020 0x202090
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00181420();                                /* extern */
s32 func_00205050(s32, s32, M2C_UNK);               /* extern */
s32 func_00205D30(s32, s32);                        /* extern */

s32 func_00202020(s32 arg0) {
    s32 temp_s0;

    if ((arg0 >= 0) && (arg0 < 4)) {
        temp_s0 = func_00181420();
        return func_00205050(temp_s0, func_00205D30(func_00181420(), arg0), 1);
    }
    return 0;
}
