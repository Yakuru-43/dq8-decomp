// range: 0x25E0C0 0x25E130
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_001007A0(s32);                         /* extern */
M2C_UNK func_00251B80(s32);                         /* extern */

s32 func_0025E0C0(s32 arg0, s64 arg1) {
    s32 temp_a0;

    if (arg0 != 0) {
        temp_a0 = arg0 + 0xC;
        if (temp_a0 != 0) {
            func_00251B80(temp_a0);
        }
        if (((s64) (arg1 << 0x30) >> 0x30) > 0) {
            func_001007A0(arg0);
        }
    }
    return arg0;
}
