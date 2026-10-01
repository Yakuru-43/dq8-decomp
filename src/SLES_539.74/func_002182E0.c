// range: 0x2182E0 0x218340
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00168160();                                /* extern */
M2C_UNK func_00208C20(s32, M2C_UNK);                /* extern */
M2C_UNK func_0020B860(s32, M2C_UNK *);              /* extern */
M2C_UNK func_003056A0();                            /* extern */
extern u8 D_003E0990;
extern M2C_UNK D_00415D60 __attribute__((section(".data")));

void func_002182E0(void) {
    s32 temp_s0;

    if (D_003E0990 != 0) {
        temp_s0 = func_00168160();
        func_003056A0();
        func_0020B860(temp_s0, &D_00415D60);
        func_00208C20(temp_s0, -0x101);
        D_003E0990 = 0;
    }
}
