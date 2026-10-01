// range: 0x293BC0 0x293C20
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_002912C0(s32);                         /* extern */
s32 func_002915F0(s32, M2C_UNK);                    /* extern */
M2C_UNK func_00292240(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_00292960();                            /* extern */

s32 func_00293BC0(s32 arg0) {
    func_00292960();
    func_00292240(arg0, 0x13, 0xA);
    if (func_002915F0(arg0, 0) > 0) {
        func_002912C0(arg0);
        return 1;
    }
    return 0;
}
