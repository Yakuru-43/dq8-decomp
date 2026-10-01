// range: 0x203C40 0x203D10
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00201D10();                            /* extern */
s32 func_00201DB0(s32);                             /* extern */
s32 func_002021D0(M2C_UNK);                         /* extern */
M2C_UNK func_00204B40(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 func_00206080();                                /* extern */
M2C_UNK func_00206900(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_00206A50(s32, M2C_UNK);                /* extern */

s32 func_00203C40(s32 arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    s32 temp_v0;

    if (func_00206080() != 0) {
        temp_v0 = func_00201DB0(arg0);
        func_00206900(temp_v0, arg1, arg2);
        if (arg3 != 0) {
            func_00206A50(temp_v0, arg1);
            func_00201D10();
        }
        if (func_002021D0(arg1) == 0) {
            func_00204B40(arg0, arg1, 0x02000000, 0);
        }
        return 1;
    }
    return -1;
}
