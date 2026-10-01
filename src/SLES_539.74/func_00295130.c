// range: 0x295130 0x2951A0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_002912C0(void *);                      /* extern */
s32 func_002915F0(void *, M2C_UNK);                 /* extern */
M2C_UNK func_00291720(void *);                      /* extern */
M2C_UNK func_00292960(void *);                      /* extern */
s32 func_00296F60(s32);                             /* extern */

s32 func_00295130(void *arg0) {
    if (!(func_00296F60(M2C_FIELD(arg0, s32 *, 0x58C)) & 0x1C0)) {
        func_00292960(arg0);
        func_00291720(arg0);
        if (func_002915F0(arg0, 0) > 0) {
            func_002912C0(arg0);
            return 1;
        }
        goto block_3;
    }
block_3:
    return 0;
}
