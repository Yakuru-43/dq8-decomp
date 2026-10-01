// range: 0x36EAA0 0x36EAE0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_003647F0(s32);                         /* extern */
M2C_UNK func_0036EA80(s32);                         /* extern */

s32 func_0036EAA0(s32 arg0) {
    func_003647F0(arg0 + 0x20);
    func_0036EA80(arg0);
    return arg0;
}
