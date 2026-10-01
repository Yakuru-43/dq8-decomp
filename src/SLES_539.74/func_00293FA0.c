// range: 0x293FA0 0x294000
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00290EA0(s32);                         /* extern */
M2C_UNK func_002914D0(s32);                         /* extern */
s32 func_002915F0(s32, M2C_UNK);                    /* extern */
M2C_UNK func_00292960();                            /* extern */

s32 func_00293FA0(s32 arg0) {
    func_00292960();
    func_00290EA0(arg0);
    if (func_002915F0(arg0, 0) > 0) {
        func_002914D0(arg0);
        return 1;
    }
    return 0;
}
