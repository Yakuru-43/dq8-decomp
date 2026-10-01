// range: 0x21FCC0 0x21FD40
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_0022A6F0(s8 *, s32);                   /* extern */
M2C_UNK func_002E4CF0(s32, s8 *);                   /* extern */
s32 func_00370500();                                /* extern */

void func_0021FCC0(s32 arg0, s8 *arg1, s32 arg2) {
    *arg1 = 0;
    if ((func_00370500() != 0) && (arg2 == 0)) {
        func_0022A6F0(arg1, arg0);
    } else {
        func_002E4CF0(arg0, arg1);
    }
}
