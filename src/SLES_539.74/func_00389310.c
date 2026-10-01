// range: 0x389310 0x389350
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00168150();                            /* extern */
s32 func_00201CC0();                                /* extern */
M2C_UNK func_00201CD0();                            /* extern */
s32 func_00372D60(s32);                             /* extern */

s32 func_00389310(void) {
    func_00201CD0();
    func_00168150();
    return func_00372D60(func_00201CC0()) != 0;
}
