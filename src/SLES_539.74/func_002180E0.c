// range: 0x2180E0 0x218180
#include "common.h"

s32 func_00218180();                                /* extern */
M2C_UNK func_00214C00(s32, M2C_UNK);                 /* extern */
M2C_UNK func_002209E0(s32, M2C_UNK);                 /* extern */
M2C_UNK func_002F6630(s32, s32);                     /* extern */
extern s32 D_00415D48 __attribute__((section(".data")));

void func_002180E0(s32 arg0, s32 arg1) {

    if (!(D_00415D48 != 0)) {
        return;
    }

    func_002F6630(D_00415D48, func_00218180() & 0xFF);

    if (arg1 == 0) {
        func_00214C00(D_00415D48, arg0);
    } else if (arg1 == 1) {
        func_002209E0(D_00415D48, arg0);
    }
}
