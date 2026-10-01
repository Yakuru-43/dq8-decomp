// range: 0x1CF790 0x1CF7F0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00133F78(s32, M2C_UNK *);                  /* extern */
M2C_UNK func_00163E70(s32);                         /* extern */
extern M2C_UNK D_003C4928 __attribute__((section(".data")));

s32 func_001CF790(void *arg0, s32 arg1) {
    s32 var_s0;

    var_s0 = 0;
    if (arg1 > 0) {
        var_s0 = M2C_FIELD(arg0, s32 *, 4);
    }
    if (func_00133F78(var_s0, &D_003C4928) == 0) {
        func_00163E70(0);
    } else {
        func_00163E70(var_s0);
    }
    return 1;
}
