// range: 0x46D0F0 0x46D170
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

s32 func_2CD2D0();                               /* extern */

void func_0046D0F0(s32 arg0, s32 arg1) {
    s32 temp_v1;
    s32 var_a1;
    s32 var_t0;
    char *temp_a3;

    var_a1 = arg1;
    if (var_a1 < 4) {
        var_a1 = func_2CD2D0(var_a1);
    }
    var_t0 = 0;
    do {
        temp_a3= (char *) ( arg0 + (var_t0 * 4));
        temp_v1 = M2C_FIELD(temp_a3, s32 *, 0xA50);
        if ((temp_v1 >= 0) && (temp_v1 == var_a1)) {
            *M2C_FIELD(temp_a3, s32 **, 0xAC8) = -1;
            M2C_FIELD(temp_a3, s32 *, 0xA50) = -1;
        }
        var_t0 += 1;
    } while (var_t0 < 0x1E);
}
