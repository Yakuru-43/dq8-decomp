// range: 0x293420 0x293480
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_002912C0(s32);                         /* extern */
s32 func_002915F0(s32, M2C_UNK);                    /* extern */
M2C_UNK func_00292570(s32);                         /* extern */
M2C_UNK func_002926D0();                            /* extern */
M2C_UNK func_00296BB0(s32);                         /* extern */

s32 func_00293420(s32 arg0) {
    func_002926D0();
    func_00292570(arg0);
    if (func_002915F0(arg0, 0) <= 0) {
        func_00296BB0(arg0);
    } else {
        func_002912C0(arg0);
    }
    return 1;
}
