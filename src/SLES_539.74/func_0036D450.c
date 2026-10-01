// range: 0x36D450 0x36D480
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_0036D450(char *arg0) {
    s32 var_a2;
    char *temp_a1;

    M2C_FIELD(arg0, s32 *, 0x58C) = 0;
    var_a2 = 0;
    do {
        temp_a1 = arg0 + (var_a2 * 8);
        var_a2 += 1;
        M2C_FIELD(temp_a1, s32 *, 0x590) = 0;
        M2C_FIELD(temp_a1, s32 *, 0x594) = 0;
    } while (var_a2 < 4);
}
