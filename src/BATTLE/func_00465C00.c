// range: 0x465C00 0x465C40
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_00465CF0();                                /* extern */
M2C_UNK func_00465ED0(s32, s32);                    /* extern */

void func_00465C00(s32 arg0) {
    s32 temp_v0;

    temp_v0 = func_00465CF0();

    if (!(temp_v0 >= 0)) {
        return;
    }

    func_00465ED0(arg0, temp_v0);
}
