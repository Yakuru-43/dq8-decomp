// range: 0x380BB0 0x380BE0
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

void func_00380BB0(s32 arg0) {
    s32 var_a1;
    char *temp_v1;

    var_a1 = 0;
    do {
        temp_v1= (char *) ( arg0 + (var_a1 * 2));
        var_a1 += 1;
        M2C_FIELD(temp_v1, s16 *, 6) = 0;
    } while (var_a1 < 5);
}
