// range: 0x1FC8B0 0x1FC930
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

s32 *func_001FC8B0(s32 *arg0) {
    s32 temp_v0;
    s32 var_a1;
    char *temp_v0_2;
    char *temp_v1;

    var_a1 = 0;
    *arg0 = 0x30;
    do {
        if (var_a1 >= 0) {
            temp_v0 = *arg0;
            if (var_a1 < temp_v0) {
                if ((var_a1 >= 0) && (var_a1 < temp_v0)) {
                    temp_v1= (char *) arg0 + (var_a1 * 4);
                    M2C_FIELD(temp_v1, s32 *, 4) = 0;
                    M2C_FIELD(temp_v1, s32 *, 0x184)= (s32) M2C_FIELD(temp_v1, s32 *, 0xC4);
                    M2C_FIELD(temp_v1, s32 *, 0x304) = 0;
                }
                temp_v0_2= (char *) arg0 + (var_a1 * 4);
                M2C_FIELD(temp_v0_2, s32 *, 0xC4) = 0;
                M2C_FIELD(temp_v0_2, s32 *, 0x184) = 0;
                M2C_FIELD(temp_v0_2, s32 *, 0x244) = 0;
                M2C_FIELD(temp_v0_2, s32 *, 0x304) = 0;
            }
        }
        var_a1 += 1;
    } while (var_a1 < 0x30);
    return arg0;
}
