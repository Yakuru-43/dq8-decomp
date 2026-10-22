// range: 0x210740 0x2107B0
#include "common.h"

s32 func_00133F78(s32, M2C_UNK *);    /* extern */

s32 func_00210740(void *arg0, s32 arg1) {
    s32 i;

    for (i = 0; i < 30; i++) {
        if (func_00133F78(arg1, (M2C_UNK *)((char *)arg0 + (i << 6) + 0x60)) == 0) {
            return 1;
        }
    }
    return 0;
}
