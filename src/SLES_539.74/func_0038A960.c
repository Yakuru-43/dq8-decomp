// range: 0x38A960 0x38AA20
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

s32 func_00372590();                             /* extern */
M2C_UNK func_003729D0();                         /* extern */
s32 func_0037BE90();                        /* extern */

void func_0038A960(s32 arg0) {
    s32 *temp_s2;
    s32 var_s0;

    var_s0 = 0;
    do {
        temp_s2= (int *) ( arg0 + (var_s0 * 4));
        if (*temp_s2 != 0) {
            if ((func_0037BE90(arg0, var_s0) & 0xFF) && (func_00372590(*temp_s2) == 2)) {
                func_003729D0(*temp_s2);
                if ((var_s0 >= 0) && (var_s0 < 4)) {
                    M2C_FIELD((arg0 + (var_s0 * 2)), s16 *, 0x20) = -1;
                }
            }
        }
        var_s0 += 1;
    } while (var_s0 < 4);
}
