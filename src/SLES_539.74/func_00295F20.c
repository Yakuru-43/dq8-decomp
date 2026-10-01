// range: 0x295F20 0x295F70
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00291D70(s32);                         /* extern */
s32 func_00295F70(s32);                             /* extern */
s32 func_00296640();                                /* extern */

s32 func_00295F20(s32 arg0) {
    if ((func_00296640() & 0xFF) == 1) {
        func_00291D70(arg0);
        return func_00295F70(arg0);
    }
    return 0;
}
