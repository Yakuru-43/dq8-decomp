// range: 0x276F20 0x276F50
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_0013D2B0();                            /* extern */
M2C_UNK func_0013E080(s32);                         /* extern */

s32 func_00276F20(s32 arg0) {
    func_0013D2B0();
    func_0013E080(arg0 + 0x40);
    return arg0;
}
