// range: 0x2203B0 0x220480
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_00222320(char *, s32);
void func_002E5800(char *, s32, s32);
void func_002203B0(char *arg0) {
    s32 var_a0;
    s32 var_a0_2;
    s32 var_s0;
    char *temp_a0;
    char *temp_v1;
    char *temp_v1_2;
    char *temp_v1_3;

    M2C_FIELD(arg0, s8 *, 0) = 0;
    M2C_FIELD(arg0, s16 *, 0x44) = 0;
    var_a0 = 0;
    do {
        temp_v1 = arg0 + (var_a0 * 2);
        var_a0 += 1;
        M2C_FIELD(temp_v1, s16 *, 0x6A) = 0;
    } while (var_a0 < 0x10);
    M2C_FIELD(arg0, s16 *, 0x46) = 0;
    var_a0_2 = 0;
    do {
        temp_v1_2 = arg0 + (var_a0_2 * 2);
        var_a0_2 += 1;
        M2C_FIELD(temp_v1_2, s16 *, 0x4A) = 0;
    } while (var_a0_2 < 0x10);
    var_s0 = 0;
    do {
        temp_v1_3 = arg0 + (var_s0 * 4);
        temp_a0 = M2C_FIELD(temp_v1_3, char **, 4);
        if (temp_a0 != NULL) {
            func_002E5800(temp_a0, -1, -1);
            if (M2C_FIELD(arg0, s8 *, 1) != 0) {
                func_00222320(M2C_FIELD(temp_v1_3, char **, 4), 0);
            }
        }
        var_s0 += 1;
    } while (var_s0 < 0x10);
    M2C_FIELD(arg0, s16 *, 0x48) = 0;
}
