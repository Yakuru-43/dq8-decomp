// range: 0x188380 0x188410
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0025E5D0(M2C_UNK *);                       /* extern */
s32 func_002C3C70();                                /* extern */
s32 func_003518B0();                                /* extern */
extern s16 D_003E04E0;
extern M2C_UNK D_0040F340 __attribute__((section(".data")));

s32 func_00188380(void) {
    s32 var_s0;

    var_s0 = 1;
    if (func_002C3C70() != 0) {
        var_s0 = 0;
    }
    if ((D_003E04E0 == 1) || (D_003E04E0 == 3)) {
        var_s0 = 0;
    }
    if (func_003518B0() != 0) {
        var_s0 = 0;
    }
    if (func_0025E5D0(&D_0040F340) != 0) {
        var_s0 = 0;
    }
    return var_s0;
}
