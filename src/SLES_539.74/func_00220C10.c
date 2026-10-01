// range: 0x220C10 0x220C60
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0021B220(s32);                             /* extern */
s32 func_00220C60();                                /* extern */
M2C_UNK func_002E5A60(s32, s32);                    /* extern */

s32 func_00220C10(s32 arg0) {
    s32 temp_s0;

    temp_s0 = func_00220C60();
    func_002E5A60(arg0, func_0021B220(arg0));
    return temp_s0;
}
