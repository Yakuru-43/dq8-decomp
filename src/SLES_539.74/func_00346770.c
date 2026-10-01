// range: 0x346770 0x346840
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00159630(s32, s32);                    /* extern */
s32 func_0015F450();                                /* extern */
M2C_UNK func_0016A430(s32, s32);                    /* extern */
M2C_UNK func_0018A030(s32, M2C_UNK);                /* extern */
s32 func_002252D0(s32);                             /* extern */
extern s32 D_00453910 __attribute__((section(".data")));
extern s16 D_00453918 __attribute__((section(".data")));

void func_00346770(s32 arg0) {
    s32 temp_s2;
    s32 var_s1;
    s32 var_s1_2;

    if (D_00453918 != 0) {
        temp_s2 = func_0015F450();
        if (D_00453910 != 0) {
            func_00159630(temp_s2, func_002252D0(D_00453910));
        }
        var_s1 = 0;
        do {
            func_00159630(temp_s2, var_s1 + 0xAC);
            var_s1 += 1;
        } while (var_s1 < 6);
        var_s1_2 = 0;
        do {
            func_0016A430(arg0, var_s1_2 + 0x24);
            var_s1_2 += 1;
        } while (var_s1_2 < 2);
        func_0016A430(arg0, 0x26);
    }
    func_0018A030(arg0, 0);
    D_00453910 = 0;
}
