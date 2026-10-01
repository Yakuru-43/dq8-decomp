// range: 0x222E80 0x222EB0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00222E10(s32);                         /* extern */
M2C_UNK func_00222EB0();                            /* extern */

s32 func_00222E80(s32 arg0) {
    func_00222EB0();
    func_00222E10(arg0);
    return arg0;
}
