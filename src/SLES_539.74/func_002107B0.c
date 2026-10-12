// range: 0x2107B0 0x210810
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

M2C_UNK func_00131188();       /* extern */

void func_002107B0(s32 arg0) {
    s32 var_s1;
    char *temp_s0;

    var_s1 = 0;
    do {
        temp_s0= (char *) ( arg0 + (var_s1 << 6));
        func_00131188(temp_s0 + 0x40, 0, 0x40);
        var_s1 += 1;
        M2C_FIELD(temp_s0, s8 *, 0x60) = 0;
    } while (var_s1 < 0x1E);
}
