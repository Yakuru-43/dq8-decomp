// range: 0x35F2E0 0x35F370
#include "common.h"

extern M2C_UNK D_00421AD0 __attribute__((section(".data")));

void *func_00359CF0(M2C_UNK *, s32);                 /* extern */
M2C_UNK *func_001814D0(void);                         /* extern */
s32 func_003083C0(M2C_UNK *, s32, s32);               /* extern */

s32 func_0035F2E0(s32 *arg0) {
    s32 *found;

    found = func_00359CF0(&D_00421AD0, 0);
    if (found != 0) {
        if (arg0[4] == found[0x38]) {
            if (arg0[5] > 0) {
                arg0[3] = arg0[3] + arg0[5];
                arg0[4] = 0;
                arg0[5] = 0;
                func_003083C0(func_001814D0(), 0x1D, 1);
                return 1;
            }
        }
    }
    return 0;
}
