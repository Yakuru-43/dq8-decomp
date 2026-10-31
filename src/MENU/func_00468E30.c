// range: 0x468E30 0x468F10
#include "common.h"

s32 func_2D34C0();                                                           /* extern */
M2C_UNK func_2D6B20(s32, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);               /* extern */
M2C_UNK func_2D6A80(s32, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, f32); /* extern */
extern f32 D_003DF744 __attribute__((section(".sdata")));

void func_00468E30(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_s2;
    s32 temp_a3;
    s32 temp_s1;
    s32 temp_t0;
    s32 temp_s0;

    temp_s2 = func_2D34C0();
    temp_a3 = (arg0 * 3 << 4) + 2;
    temp_s1 = (arg0 * 3 << 4) + 0x20;
    temp_t0 = (arg1 * 3 << 4) + 0x1E;
    temp_s0 = (arg1 * 3 << 4) + 0x16;
    if (arg2 != 0) {
        func_2D6B20(temp_s2, 0x586, 0x18703, temp_a3, temp_t0);
        func_2D6B20(temp_s2, 0x586, 0x485, temp_s1, temp_s0);
    } else {
        func_2D6A80(temp_s2, 0x586, 0x18703, temp_a3, temp_t0, 0, D_003DF744);
        func_2D6B20(temp_s2, 0x586, 0x485, temp_s1, temp_s0);
    }
}
