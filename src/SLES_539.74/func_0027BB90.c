// range: 0x27BB90 0x27BBF0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00131188(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_0014E8A0(s32);                         /* extern */
M2C_UNK func_00169150(s32);                         /* extern */
M2C_UNK func_0019B190(s32);                         /* extern */
M2C_UNK func_002226A0(s32);                         /* extern */

s32 func_0027BB90(s32 arg0) {
    func_0014E8A0(arg0 + 0x36C);
    func_002226A0(arg0 + 0x3F0);
    func_00169150(arg0 + 0x2350);
    func_00131188(arg0, 0, 0x23C0);
    func_0019B190(arg0 + 0x2350);
    return arg0;
}
