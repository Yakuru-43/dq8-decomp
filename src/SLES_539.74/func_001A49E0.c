// range: 0x1A49E0 0x1A4A20
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_001A4950(s32);                         /* extern */
M2C_UNK func_001AACB0(s32);                         /* extern */

s32 func_001A49E0(s32 arg0) {
    func_001AACB0(arg0 + 0x140);
    func_001A4950(arg0);
    return arg0;
}
