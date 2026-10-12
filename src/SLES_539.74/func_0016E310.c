// range: 0x16E310 0x16E360
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

void func_0016E310(s32 arg0) {
    s32 var_a1;
    s32 var_a1_2;
    char *temp_v1;
    char *temp_v1_2;

    var_a1 = 0;
    do {
        temp_v1= (char *) ( arg0 + (var_a1 * 8));
        var_a1 += 1;
        M2C_FIELD(temp_v1, s32 *, 0x14) = 0;
    } while (var_a1 < 0x80);
    var_a1_2 = 0;
    do {
        temp_v1_2= (char *) ( arg0 + (var_a1_2 * 8));
        var_a1_2 += 1;
        M2C_FIELD(temp_v1_2, s32 *, 0x414) = 0;
    } while (var_a1_2 < 0x20);
}
