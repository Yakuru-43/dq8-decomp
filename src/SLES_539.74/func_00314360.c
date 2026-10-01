// range: 0x314360 0x3143E0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00131188(char *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_0018DCB0(char *, M2C_UNK, M2C_UNK);    /* extern */

void func_00314360(char *arg0) {
    s32 var_a1;
    char *temp_a0;

    M2C_FIELD(arg0, s32 *, 0x140) = 0;
    func_0018DCB0(arg0 + 0x144, 0, 0);
    func_00131188(arg0 + 0x100, -1, 0x1A);
    func_00131188(arg0 + 0x11A, 0, 0x20);
    M2C_FIELD(arg0, s16 *, 0x13C) = 0;
    var_a1 = 0;
    M2C_FIELD(arg0, s16 *, 0x13A) = 0;
    do {
        temp_a0 = arg0 + (var_a1 * 4);
        var_a1 += 1;
        M2C_FIELD(temp_a0, s32 *, 0) = 0;
        M2C_FIELD(temp_a0, s32 *, 0x80) = 0;
    } while (var_a1 < 0x20);
}
