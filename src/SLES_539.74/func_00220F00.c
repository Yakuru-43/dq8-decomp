// range: 0x220F00 0x220F60
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00220EF0();                            /* extern */
M2C_UNK func_002E5A60(s32, s32);                    /* extern */
M2C_UNK func_002E5C90(s32, M2C_UNK, M2C_UNK);       /* extern */

void func_00220F00(s32 arg0, s32 arg1) {
    func_00220EF0();
    func_002E5A60(arg0, arg1);
    if (arg1 < 0) {
        func_002E5C90(arg0, -1, -1);
    }
}
