// range: 0x2333A0 0x2333E0
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_002333A0(char *arg0) {
    s32 var_a1;
    char *temp_v1;

    M2C_FIELD(arg0, s32 *, 0) = 0;
    var_a1 = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s16 *, 0x18) = 0;
    M2C_FIELD(arg0, s16 *, 0x1A) = 0;
    do {
        temp_v1 = arg0 + (var_a1 * 4);
        var_a1 += 1;
        M2C_FIELD(temp_v1, s32 *, 8) = 0;
    } while (var_a1 < 4);
}
