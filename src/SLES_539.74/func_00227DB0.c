// range: 0x227DB0 0x227E10
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00220700(s32, s32, M2C_UNK);           /* extern */
s32 func_00227E80();                                /* extern */
M2C_UNK func_002F6630(s32, s32);                    /* extern */
extern s32 D_003E0A9C;

void func_00227DB0(s32 arg0, M2C_UNK arg1) {

    if (!(D_003E0A9C != 0)) {
        return;
    }

    func_002F6630(D_003E0A9C, func_00227E80() & 0xFF);
    func_00220700(D_003E0A9C, arg0, arg1);
}
