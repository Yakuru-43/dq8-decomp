// range: 0x295910 0x295980
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_002912C0(s32);                         /* extern */
s32 func_002915F0(s32, M2C_UNK);                    /* extern */
M2C_UNK func_00291820(s32);                         /* extern */
s32 func_00296640();                                /* extern */

s32 func_00295910(s32 arg0) {
    if ((func_00296640() & 0xFF) == 1) {
        func_00291820(arg0);
        if (func_002915F0(arg0, 0) > 0) {
            func_002912C0(arg0);
            return 1;
        }
        goto block_3;
    }
block_3:
    return 0;
}
