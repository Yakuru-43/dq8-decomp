// range: 0x294420 0x294480
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_002912C0(s32);                         /* extern */
s32 func_002915F0(s32, M2C_UNK);                    /* extern */
M2C_UNK func_00292570(s32);                         /* extern */
M2C_UNK func_00292960();                            /* extern */

s32 func_00294420(s32 arg0) {
    func_00292960();
    func_00292570(arg0);
    if (func_002915F0(arg0, 0) > 0) {
        func_002912C0(arg0);
        return 1;
    }
    return 0;
}
