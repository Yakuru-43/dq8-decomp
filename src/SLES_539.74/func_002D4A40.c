// range: 0x2D4A40 0x2D4A80
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_001EE340(s32, M2C_UNK);                /* extern */
s32 func_002D76A0();                                /* extern */

void func_002D4A40(s32 arg0, s32 arg1, M2C_UNK arg2) {
    s32 temp_v0;

    temp_v0 = func_002D76A0();

    if (!(temp_v0 != 0)) {
        return;
    }

    func_001EE340(temp_v0 + 0x10, arg2);
}
