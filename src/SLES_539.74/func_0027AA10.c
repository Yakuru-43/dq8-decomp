// range: 0x27AA10 0x27AA60
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00157480(s32);                         /* extern */
M2C_UNK func_0015C030(s32);                         /* extern */

s32 func_0027AA10(s32 arg0) {
    func_0015C030(arg0 + 0x30);
    func_0015C030(arg0 + 0x98);
    func_0015C030(arg0 + 0x110);
    func_00157480(arg0);
    return arg0;
}
