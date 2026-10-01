// range: 0x3647F0 0x364840
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00363510(s32);                         /* extern */
M2C_UNK func_0036B070(s32);                         /* extern */

s32 func_003647F0(s32 arg0) {
    func_00363510(arg0 + 0x58);
    func_00363510(arg0 + 0xB0);
    func_00363510(arg0 + 0x108);
    func_00363510(arg0 + 0x40C);
    func_0036B070(arg0);
    return arg0;
}
