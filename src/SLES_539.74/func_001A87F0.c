// range: 0x1A87F0 0x1A8830
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_001A86E0(s32);                         /* extern */
M2C_UNK func_001AB170(s32);                         /* extern */

s32 func_001A87F0(s32 arg0) {
    func_001AB170(arg0 + 0x220);
    func_001A86E0(arg0);
    return arg0;
}
