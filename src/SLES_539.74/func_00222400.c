// range: 0x222400 0x222460
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_002219F0();                            /* extern */
M2C_UNK func_00222370(s32, M2C_UNK);                /* extern */
M2C_UNK func_002E6740(s32, M2C_UNK, M2C_UNK);       /* extern */

void func_00222400(s32 arg0, s32 arg1) {
    func_002219F0();
    if (arg1 == 1) {
        func_002E6740(arg0, 0, 8);
        func_00222370(arg0, 8);
    }
}
