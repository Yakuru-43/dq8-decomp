// range: 0x4632A0 0x463360
#include "common.h"

s32 func_2D34C0();                                                          /* extern */
M2C_UNK func_2D6B20(s32, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);               /* extern */
M2C_UNK func_2D6A80(s32, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, f32); /* extern */
M2C_UNK func_37EA60(M2C_UNK);                                               /* extern */
extern f32 D_003DF744 __attribute__((section(".sdata")));

void func_004632A0(s32 arg0, s32 arg1) {
    s32 temp_s2;
    s32 temp_s1;

    temp_s2 = func_2D34C0();
    if (arg1 != 0) {
        temp_s1 = arg0 + 0x2AF8;
        func_2D6B20(temp_s2, temp_s1, 0x18703, -8, 0x18);
    } else {
        temp_s1 = arg0 + 0x2AF8;
        func_2D6A80(temp_s2, temp_s1, 0x18703, -8, 0x18, 0, D_003DF744);
    }
    func_37EA60(arg0);
    func_2D6B20(temp_s2, temp_s1, 0x4A6, 0, 0);
}
