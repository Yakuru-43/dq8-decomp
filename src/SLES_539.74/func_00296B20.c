// range: 0x296B20 0x296B50
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00291400(s32);                         /* extern */
M2C_UNK func_00292960();                            /* extern */

s32 func_00296B20(s32 arg0) {
    func_00292960();
    func_00291400(arg0);
    return 1;
}
