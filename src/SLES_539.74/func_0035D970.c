// range: 0x35D970 0x35D9E0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_0035D9E0(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 func_0035E590();                                /* extern */

void func_0035D970(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    if (func_0035E590() != 0) {
        func_0035D9E0(arg0, arg1, arg2, 1);
    } else {
        M2C_FIELD(arg0, s8 *, 0x561) = 1;
        M2C_FIELD(arg0, s8 *, 0x560) = 1;
    }
}
