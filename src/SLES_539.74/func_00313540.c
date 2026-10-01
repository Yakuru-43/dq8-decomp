// range: 0x313540 0x313580
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00109220(M2C_UNK);                     /* extern */

void func_00313540(void) {
    s32 var_s0;

    var_s0 = 0;
    do {
        func_00109220(0);
        var_s0 += 1;
    } while (var_s0 < 0xB4);
}
