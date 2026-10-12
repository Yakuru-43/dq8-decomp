// range: 0x2217C0 0x221830
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_00181420();                                /* extern */
s32 func_00205D30(s32, M2C_UNK);                    /* extern */
s32 func_00221830(s32);                             /* extern */
M2C_UNK func_002F5FE0(s32, M2C_UNK, s32);           /* extern */

void func_002217C0(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 temp_v0;

    temp_v0 = func_00181420();

    if (!(temp_v0 != 0)) {
        return;
    }

    func_002F5FE0(arg0, arg1, func_00221830(func_00205D30(temp_v0, arg2)));
}
