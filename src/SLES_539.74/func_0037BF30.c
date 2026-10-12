// range: 0x37BF30 0x37BF90
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

void func_0037BF30(char *arg0) {
    s32 *temp_v1;
    s32 var_a1;
    s32 var_a2;

    var_a1 = 0;
    do {
        temp_v1= (int *) ( arg0 + (var_a1 * 4));
        var_a1 += 1;
        *temp_v1 = 0;
    } while (var_a1 < 4);
    var_a2 = 0;
    do {
        M2C_FIELD((arg0 + var_a2), s8 *, 0x10) = 1;
        var_a2 += 1;
    } while (var_a2 < 4);
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, s32 *, 0x18) = -1;
}
