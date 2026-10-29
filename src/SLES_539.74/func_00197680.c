// range: 0x197680 0x1976C0
#include "common.h"

extern u8 D_0041C8D0[];

void func_00197680(f32 arg0) {
    u8 *var_a1;
    s32 var_a0;
    char *temp_v1;

    var_a0 = 0;
    var_a1 = D_0041C8D0;
    do {
        temp_v1 = *(char **)(var_a1 + 0x14);
        if (temp_v1 != NULL) {
            *(f32 *)(temp_v1 + 0x15FC) = arg0;
        }
        var_a0 += 1;
        var_a1 += 0x18;
    } while (var_a0 < 4);
}
