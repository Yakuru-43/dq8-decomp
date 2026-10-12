// range: 0x218070 0x2180E0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_00218180();                                /* extern */
M2C_UNK func_00220700(s32, s32, M2C_UNK);           /* extern */
M2C_UNK func_002F6630(s32, s32);                    /* extern */
extern s32 D_00415D48 __attribute__((section(".data")));

void func_00218070(s32 arg0, M2C_UNK arg1) {

    if (!(D_00415D48 != 0)) {
        return;
    }

    func_002F6630(D_00415D48, func_00218180() & 0xFF);
    func_00220700(D_00415D48, arg0, arg1);
}
