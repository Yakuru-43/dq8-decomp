// range: 0x3397B0 0x3397F0
#include "common.h"

extern s32 D_004534E0[0x20];

void func_003397B0(void) {
    s32 *var_a2;
    s32 var_a1;
    s32 var_a0;

    var_a1 = 0;
    var_a2 = D_004534E0;
    var_a0 = -1;
    do {
        var_a2[0] = 0;
        var_a1 += 1;
        var_a2[1] = var_a0;
        var_a2[2] = var_a0;
        var_a2 += 3;
    } while (var_a1 < 0x20);
}
