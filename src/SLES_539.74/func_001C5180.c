// range: 0x1C5180 0x1C5220
#include "common.h"

extern s32 D_003E06FC;
M2C_UNK func_001A3520(s32, M2C_UNK32, s32);

s32 func_001C5180(char *arg0) {
    s32 a2;
    s32 a1;
    void *var_a0;

    if (*(s32 *)(arg0 + 0) == 1) {
        a2 = (s32)*(f32 *)(arg0 + 4);
    } else {
        a2 = *(s32 *)(arg0 + 4);
    }

    if (*(s32 *)(arg0 + 8) == 1) {
        a1 = (s32)*(f32 *)(arg0 + 0xC);
    } else {
        a1 = *(s32 *)(arg0 + 0xC);
    }

    if (a2 >= 0 && a2 < 0x20) {
        var_a0 = (void *)(D_003E06FC + a2 * 0x5F0);
    } else {
        var_a0 = 0;
    }

    if (var_a0 == 0) {
        return 0;
    }

    func_001A3520((s32)var_a0, a1, a2);
    return 1;
}
