// range: 0x294130 0x294190
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_002914D0(s32);                         /* extern */
s32 func_002915F0(s32, M2C_UNK);                    /* extern */
M2C_UNK func_00292460(s32, M2C_UNK);                /* extern */
M2C_UNK func_00292960();                            /* extern */

s32 func_00294130(s32 arg0) {
    func_00292960();
    func_00292460(arg0, 0x40000);
    if (func_002915F0(arg0, 0) > 0) {
        func_002914D0(arg0);
        return 1;
    }
    return 0;
}
