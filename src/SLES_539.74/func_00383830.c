// range: 0x383830 0x3838A0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001814D0();                                /* extern */
s32 func_00278940(s32);                             /* extern */
s32 func_002B0EB0(s32, s32);                        /* extern */
s32 func_003838A0(M2C_UNK *, s32);                  /* extern */
extern M2C_UNK D_004590F0 __attribute__((section(".data")));

s32 func_00383830(s32 arg0) {
    s32 var_s0;

    var_s0 = 0;
    if (func_002B0EB0(func_00278940(func_001814D0()), arg0) == 0) {
        var_s0 = 2;
    }
    if (func_003838A0(&D_004590F0, arg0) != 0) {
        var_s0 = 1;
    }
    return var_s0;
}
