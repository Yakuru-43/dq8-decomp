// range: 0x314620 0x314680
#include "common.h"

void func_00159630(s32, s32);
s32 func_0015F450(void);
extern s16 D_003E11A8;
extern s16 D_003E11AC;

void func_00314620(void) {
    s32 temp_s1;
    s32 var_s0;

    temp_s1 = func_0015F450();
    var_s0 = 0;
    while (var_s0 < D_003E11AC) {
        func_00159630(temp_s1, D_003E11A8 + var_s0);
        var_s0 += 1;
    }
}
