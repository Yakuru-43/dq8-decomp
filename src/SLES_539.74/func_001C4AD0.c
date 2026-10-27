// range: 0x1C4AD0 0x1C4B70
#include "common.h"

extern s32 D_003E06FC;
M2C_UNK func_001A2FA0(f32, s32, s32);

s32 func_001C4AD0(char *arg0) {
    s32 a1;
    f32 f12;
    void *var_a0;

    if (*(s32 *)(arg0 + 0) == 1) {
        a1 = (s32)*(f32 *)(arg0 + 4);
    } else {
        a1 = *(s32 *)(arg0 + 4);
    }

    if (*(s32 *)(arg0 + 8) == 0) {
        f12 = (f32)*(s32 *)(arg0 + 0xC);
    } else {
        f12 = *(f32 *)(arg0 + 0xC);
    }

    if (a1 >= 0 && a1 < 0x20) {
        var_a0 = (void *)(D_003E06FC + a1 * 0x5F0);
    } else {
        var_a0 = 0;
    }

    if (var_a0 == 0) {
        return 0;
    }

    func_001A2FA0(f12, (s32)var_a0, a1);
    return 1;
}
