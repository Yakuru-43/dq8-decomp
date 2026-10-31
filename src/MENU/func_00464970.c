// range: 0x464970 0x464A20
#include "common.h"

s32 func_2D34C0();                                                           /* extern */
M2C_UNK func_2D6B20(s32, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_2D6A80(s32, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, f32);  /* extern */
M2C_UNK func_37CF20(M2C_UNK);                                                /* extern */
M2C_UNK func_37D060(M2C_UNK);                                                /* extern */
extern f32 D_003DF744 __attribute__((section(".sdata")));

void func_00464970(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = func_2D34C0();
    if (arg1 != 0) {
        func_2D6B20(temp_v0, arg0 + 0x2AF8, 0x18703, -0xE, 0x12);
        temp_v0 = 4;
    } else {
        func_2D6A80(temp_v0, arg0 + 0x2AF8, 0x18703, -0xE, 0x12, 0, D_003DF744);
        temp_v0 = 4;
    }
    if (arg0 == temp_v0) {
        func_37CF20(5);
    } else {
        func_37D060(arg0);
    }
}
