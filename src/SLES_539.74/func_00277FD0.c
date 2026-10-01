// range: 0x277FD0 0x278050
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00133F78(M2C_UNK, M2C_UNK *);              /* extern */
extern M2C_UNK D_003CA0C0 __attribute__((section(".data")));
extern M2C_UNK D_003CA0C8 __attribute__((section(".data")));

void func_00277FD0(void *arg0, M2C_UNK arg1) {
    s8 var_s0;

    var_s0 = 1;
    if (func_00133F78(arg1, &D_003CA0C0) == 0) {
        var_s0 = 2;
    } else if (func_00133F78(arg1, &D_003CA0C8) == 0) {
        var_s0 = 3;
    }
    M2C_FIELD(arg0, s8 *, 0x48) = var_s0;
}
