// range: 0x4699A0 0x469A30
#include "common.h"

s32 func_2D34C0();                                                           /* extern */
M2C_UNK func_2D6B20(s32, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_2D6A80(s32, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, f32);  /* extern */
M2C_UNK func_37D060(M2C_UNK);                                                /* extern */
extern f32 D_003DF388 __attribute__((section(".sdata")));

void func_004699A0(s32 arg0, s32 arg1) {
    s32 temp_v0;
    s32 temp_a1;

    temp_v0 = func_2D34C0();
    temp_a1 = arg0 + 0x2AF8;
    if (arg1 != 0) {
        func_2D6B20(temp_v0, temp_a1, 0x18703, -0xA, 0x14);
    } else {
        func_2D6A80(temp_v0, temp_a1, 0x18703, -0xA, 0x14, 0, D_003DF388);
    }
    func_37D060(arg0);
}
