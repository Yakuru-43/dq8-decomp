// range: 0x2565C0 0x256620
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

s32 func_00256620();                                /* extern */

s32 func_002565C0(s32 arg0, s32 arg1) {
    s32 temp_a0;
    s32 temp_v0;
    s32 var_a2;
    char *temp_v1;

    temp_v0 = func_00256620();
    if (temp_v0 == 0) {
        return 0;
    }
    var_a2 = 0;
    do {
        temp_a0 = var_a2 * 4;
        temp_v1= (char *) ( temp_v0 + temp_a0);
        var_a2 += 1;
        *(s32 *) (arg1 + temp_a0) = M2C_FIELD(temp_v1, s32 *, 0x44);
    } while (var_a2 < 0x10);
    return 1;
}
