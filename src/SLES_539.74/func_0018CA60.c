// range: 0x18CA60 0x18CAA0
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_0018CA60(char *arg0) {
    s32 var_a2;
    char *temp_v1;

    M2C_FIELD(arg0, s32 *, 0x6B1C) = 0;
    var_a2 = 0;
    do {
        temp_v1 = arg0 + (var_a2 * 4);
        var_a2 += 1;
        M2C_FIELD(temp_v1, s32 *, 0x6B20) = -1;
    } while (var_a2 < 2);
    M2C_FIELD(arg0, s32 *, 0x6B28) = 1;
}
