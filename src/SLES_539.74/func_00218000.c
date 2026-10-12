// range: 0x218000 0x218070
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_001FFB60(s32, s32);                    /* extern */
s32 func_00218180();                                /* extern */
M2C_UNK func_00220750(s32, M2C_UNK);                /* extern */
M2C_UNK func_002F6630(s32, s32);                    /* extern */
extern s32 D_00415D48 __attribute__((section(".data")));

void func_00218000(s32 arg0, M2C_UNK arg1) {

    if (!(D_00415D48 != 0)) {
        return;
    }

    func_002F6630(D_00415D48, func_00218180() & 0xFF);
    func_001FFB60(D_00415D48, arg0);
    func_00220750(D_00415D48, arg1);
}
