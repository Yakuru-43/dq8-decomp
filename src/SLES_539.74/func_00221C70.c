// range: 0x221C70 0x221CF0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_00181420();                                /* extern */
s32 func_00205CA0(s32, M2C_UNK);                    /* extern */
M2C_UNK func_00221570(s32, s32, M2C_UNK);           /* extern */
M2C_UNK func_00221D70(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_00221C70(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 temp_v0;

    temp_v0 = func_00181420();

    if (!(temp_v0 != 0)) {
        return;
    }

    func_00221570(arg0, func_00205CA0(temp_v0, arg2), arg1);
    func_00221D70(arg0, arg1, arg2, 0);
}
