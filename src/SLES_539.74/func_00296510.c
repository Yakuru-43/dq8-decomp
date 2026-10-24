// range: 0x296510 0x296590
#include "common.h"

M2C_UNK func_002914D0(s32);                         /* extern */
s32 func_002915F0(s32, M2C_UNK);                    /* extern */
M2C_UNK func_00292460(s32, M2C_UNK);                /* extern */
M2C_UNK func_00292960();                            /* extern */

s32 func_00296510(s32 arg0) {
    s32 before;

    func_00292960();
    before = func_002915F0(arg0, 0);
    func_00292460(arg0, 0x800);
    if (func_002915F0(arg0, 0) * 3 > before * 2) {
        func_002914D0(arg0);
        return 1;
    }
    return 0;
}
