// range: 0x28F460 0x28F4C0
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

void func_0014E500(s32, char *);
s32 func_0028F460(s32 arg0) {
    s32 var_s0;
    s8 *temp_a1;

    var_s0 = 0;
    do {
        temp_a1 = M2C_FIELD((arg0 + (var_s0 * 4)), s8 **, 0x464);
        if (temp_a1 != NULL) {
            func_0014E500(arg0, (char *) (temp_a1));
        }
        var_s0 += 1;
    } while (var_s0 < 0x20);
    return 0;
}
