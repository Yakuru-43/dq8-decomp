// range: 0x1D1FD0 0x1D2080
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

M2C_UNK func_00131188(char *, M2C_UNK, M2C_UNK);    /* extern */

void func_001D1FD0(s32 arg0) {
    s32 var_s0;
    char *temp_s2;

    var_s0 = 0;
    do {
        temp_s2= (char *) ( arg0 + (var_s0 * 0x88));
        M2C_FIELD(temp_s2, s32 *, 0) = 0;
        M2C_FIELD(temp_s2, s32 *, 4) = 0;
        func_00131188(temp_s2 + 8, 0, 0x40);
        func_00131188(temp_s2 + 0x48, 0, 0x10);
        func_00131188(temp_s2 + 0x58, 0, 0x10);
        func_00131188(temp_s2 + 0x68, 0, 0x10);
        func_00131188(temp_s2 + 0x78, -1, 0x10);
        var_s0 += 1;
    } while (var_s0 < 8);
}
