// range: 0x37B510 0x37B5A0
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

M2C_UNK func_003729D0();                         /* extern */

void func_0037B510(s32 arg0) {
    s32 temp_a0;
    s32 var_s0;

    var_s0 = 0;
    do {
        if ((var_s0 >= 0) && (var_s0 < 4)) {
            temp_a0 = *(s32 *) (arg0 + (var_s0 * 4));
            if (0 != temp_a0) {
                func_003729D0(temp_a0);
                if ((var_s0 >= 0) && (var_s0 < 4)) {
                    M2C_FIELD((arg0 + var_s0), s8 *, 0x10) = 1;
                }
            }
        }
        var_s0 += 1;
    } while (var_s0 < 4);
}
