// range: 0x460C00 0x460D00
#include "common.h"

s32 func_2D34C0();                                                                /* extern */
M2C_UNK func_2D6B20(s32, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);                     /* extern */
M2C_UNK func_2D6A80(s32, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, f32);       /* extern */
M2C_UNK func_2D38E0(s32, M2C_UNK, M2C_UNK, M2C_UNK);                              /* extern */

void func_00460C00(s32 arg0, s32 arg1, f32 arg2) {
    s32 temp_s1;
    s32 temp_s0;
    s32 temp_v0;

    temp_s1 = func_2D34C0();
    temp_s0 = arg0 + 0x2AF8;
    if (arg1 != 0) {
        func_2D6B20(temp_s1, temp_s0, 0x18703, -0xE, 0x1A);
        temp_v0 = 4;
    } else {
        func_2D6A80(temp_s1, temp_s0, 0x18703, -0xE, 0x1A, 0, arg2);
        temp_v0 = 4;
    }
    if (arg0 == temp_v0) {
        func_2D38E0(temp_s1, 0x186E7, 0, -1);
    } else {
        func_2D38E0(temp_s1, 0x186E7, 1, -1);
    }
    func_2D6B20(temp_s1, temp_s0, 0x4A6, 0, 0);
}
