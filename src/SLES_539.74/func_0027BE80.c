// range: 0x27BE80 0x27BEB0
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

s16 *func_0027BE80(s16 *arg0) {
    s32 var_v1;
    char *temp_v0;

    var_v1 = 0;
    *arg0 = -1;
    do {
        temp_v0= (char *) arg0 + (var_v1 * 0x10);
        var_v1 += 1;
        M2C_FIELD(temp_v0, s128 *, 0x10) = 0;
    } while (var_v1 < 4);
    return arg0;
}
