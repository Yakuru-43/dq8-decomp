// range: 0x295480 0x2954D0
#include "common.h"

s32 func_002915F0(s32, M2C_UNK);                    /* extern */
M2C_UNK func_00292370(s32, M2C_UNK);                /* extern */
M2C_UNK func_00292960();                            /* extern */
s32 func_00296510(s32);                             /* extern */

s32 func_00295480(s32 arg0) {
    func_00292960();
    func_00292370(arg0, 0x18);
    if (func_002915F0(arg0, 0) > 0) {
        return func_00296510(arg0);
    }
    return 0;
}
