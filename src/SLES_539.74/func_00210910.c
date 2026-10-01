// range: 0x210910 0x210950
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00210810(s32);                         /* extern */
M2C_UNK func_00210950(s32);                         /* extern */

s32 func_00210910(s32 arg0) {
    func_00210950(arg0 + 0xA00);
    func_00210810(arg0);
    return arg0;
}
