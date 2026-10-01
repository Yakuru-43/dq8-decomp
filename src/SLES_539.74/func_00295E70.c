// range: 0x295E70 0x295EC0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00291D70(s32);                         /* extern */
s32 func_00295EC0(s32);                             /* extern */
s32 func_00296590();                                /* extern */

s32 func_00295E70(s32 arg0) {
    if ((func_00296590() & 0xFF) == 1) {
        func_00291D70(arg0);
        return func_00295EC0(arg0);
    }
    return 0;
}
