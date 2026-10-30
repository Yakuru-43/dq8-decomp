// range: 0x467110 0x4671D0
#include "common.h"

s32 func_2D34C0();                                          /* extern */
M2C_UNK func_2D38E0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_2D3ED0(s32, M2C_UNK, M2C_UNK);                 /* extern */
M2C_UNK func_2D3F80(s32, M2C_UNK, M2C_UNK);                 /* extern */

void func_00467110(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = func_2D34C0();
    if (!(temp_v0 != 0)) {
        return;
    }
    if (arg0 != 0) {
        func_2D38E0(temp_v0, 0x2B82, 1, -1);
    } else {
        func_2D38E0(temp_v0, 0x2B82, 0, -1);
    }
    func_2D3F80(temp_v0, 0x2B82, 0);
    if (arg1 != 0) {
        func_2D3ED0(temp_v0, 0x590, 0x2B82);
    } else {
        func_2D3ED0(temp_v0, 0x2B83, 0x2B82);
    }
}
