// range: 0x296280 0x2962F0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00291400(s32);                         /* extern */
s32 func_00291520(s32, M2C_UNK);                    /* extern */
M2C_UNK func_00291F40(s32);                         /* extern */
M2C_UNK func_00292460(s32, M2C_UNK);                /* extern */
M2C_UNK func_00292960();                            /* extern */

s32 func_00296280(s32 arg0) {
    func_00292960();
    func_00292460(arg0, 0x8000);
    func_00292460(arg0, 0x800);
    func_00291F40(arg0);
    if (func_00291520(arg0, 0) > 0) {
        func_00291400(arg0);
        return 1;
    }
    return 0;
}
