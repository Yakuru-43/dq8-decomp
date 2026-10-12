// range: 0x204A70 0x204AB0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_002061F0();                                /* extern */
M2C_UNK func_00207B40(s32, M2C_UNK, M2C_UNK);       /* extern */

void func_00204A70(s32 arg0, s32 arg1, M2C_UNK arg2) {
    s32 temp_v0;

    temp_v0 = func_002061F0();

    if (!(temp_v0 != 0)) {
        return;
    }

    func_00207B40(temp_v0, arg2, 1);
}
