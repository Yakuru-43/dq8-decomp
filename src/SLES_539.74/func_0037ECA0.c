// range: 0x37ECA0 0x37ECF0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_002D34C0();                                /* extern */
M2C_UNK func_002D5440(s32, s32, M2C_UNK);           /* extern */

void func_0037ECA0(s32 arg0, M2C_UNK arg1) {
    s32 temp_v0;

    temp_v0 = func_002D34C0();

    if (!(temp_v0 != 0)) {
        return;
    }

    func_002D5440(temp_v0, arg0 + 4, arg1);
}
