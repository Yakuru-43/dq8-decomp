// range: 0x361A10 0x361A70
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0014DF10();                         /* extern */

void func_00361A10(char *arg0) {
    s32 var_a0;
    char *temp_v1;

    func_0014DF10(arg0 + 0xC);
    M2C_FIELD(arg0, s32 *, 0x64) = 0;
    M2C_FIELD(arg0, s32 *, 4) = -1;
    var_a0 = 0;
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s8 *, 8) = 0;
    do {
        temp_v1 = arg0 + (var_a0 * 4);
        var_a0 += 1;
        M2C_FIELD(temp_v1, s32 *, 0x68) = 0;
    } while (var_a0 < 0x80);
}
