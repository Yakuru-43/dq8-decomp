// range: 0x465C90 0x465CF0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_00465CF0();                                /* extern */
M2C_UNK func_00465DD0(s32, s32, M2C_UNK, M2C_UNK);  /* extern */

void func_00465C90(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3) {
    s32 temp_v0;

    temp_v0 = func_00465CF0();

    if (!(temp_v0 >= 0)) {
        return;
    }

    func_00465DD0(arg0, temp_v0, arg2, arg3);
}
