// range: 0x2962F0 0x296350
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00291400(s32);                         /* extern */
s32 func_00291520(s32, M2C_UNK);                    /* extern */
M2C_UNK func_00292460(s32, M2C_UNK);                /* extern */
M2C_UNK func_00292960();                            /* extern */

s32 func_002962F0(s32 arg0) {
    func_00292960();
    func_00292460(arg0, 0x8000);
    if (func_00291520(arg0, 0) > 0) {
        func_00291400(arg0);
        return 1;
    }
    return 0;
}
