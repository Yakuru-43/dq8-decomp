// range: 0x3240F0 0x324150
// auto: m2c, verified byte-exact
#include "common.h"

u32 func_003216B0(M2C_UNK *, s8 *, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK D_004532D0 __attribute__((section(".data")));

s32 func_003240F0(s8 *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    if ((arg0 != NULL) && (*arg0 != 0)) {
        return ((func_003216B0(&D_004532D0, arg0, arg1, arg2) >> 2) + 1) * 4;
    }
    return 0;
}
