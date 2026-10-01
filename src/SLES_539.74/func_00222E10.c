// range: 0x222E10 0x222E70
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00222E70(s32, M2C_UNK);                /* extern */
M2C_UNK func_002DEC30();                            /* extern */
M2C_UNK func_002E19B0(s32, M2C_UNK);                /* extern */
M2C_UNK func_002E2240(s32, M2C_UNK);                /* extern */
M2C_UNK func_002E2330(s32, M2C_UNK, M2C_UNK);       /* extern */

void func_00222E10(s32 arg0) {
    func_002DEC30();
    func_002E2330(arg0, 0x10, 0x14);
    func_002E19B0(arg0, 1);
    func_00222E70(arg0, 4);
    func_002E2240(arg0, 0x80585A5B);
}
