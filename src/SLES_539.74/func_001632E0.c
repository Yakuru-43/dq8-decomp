// range: 0x1632E0 0x163330
#include "common.h"

extern s32 D_003E02EC;
extern s32 D_003E02F0;
extern s32 D_003E02F4;
extern u8 D_003F27D0[];

void func_001632E0(void) {
    s32 temp_v1;
    s32 var_a2;

    var_a2 = 0;
    do {
        temp_v1 = var_a2 * 0x128;
        var_a2 += 1;
        *(s32 *)(D_003F27D0 + temp_v1 + 0x120) = 0;
    } while (var_a2 < 0x20);
    D_003E02F4 = 0;
    D_003E02F0 = -1;
    D_003E02EC = 0;
}
