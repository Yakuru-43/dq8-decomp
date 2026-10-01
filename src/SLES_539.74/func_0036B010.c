// range: 0x36B010 0x36B070
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_001340C0(s32, s32);                    /* extern */
s32 func_003640B0(M2C_UNK);                         /* extern */

void func_0036B010(s32 arg0, M2C_UNK arg1) {
    if (func_003640B0(arg1) != 0) {
        func_001340C0(arg0, func_003640B0(arg1));
    }
}
