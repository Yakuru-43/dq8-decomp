// range: 0x36E6E0 0x36E760
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_002F6650(s32);                         /* extern */
s32 func_0036E5C0();                                /* extern */

s32 func_0036E6E0(void *arg0, s32 arg1) {
    s32 var_s1;

    if ((func_0036E5C0() & 0xFF) && (arg1 == 0)) {
        return 0;
    }
    M2C_FIELD(arg0, s8 *, 0) = 0;
    var_s1 = 0;
    do {
        func_002F6650(M2C_FIELD(arg0, s32 *, 0xC) + (var_s1 * 0x1F18));
        var_s1 += 1;
    } while (var_s1 < 2);
    return 1;
}
