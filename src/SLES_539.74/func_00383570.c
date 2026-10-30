// range: 0x383570 0x383630
#include "common.h"

s32 func_002D34C0(void);
M2C_UNK func_002D4240(s32, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_002D4480(s32, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_002D6430(s32, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
extern s8 D_003E15D4;

void func_00383570(void) {
    s32 temp_v0;

    temp_v0 = func_002D34C0();
    func_002D4240(temp_v0, 0x138C, 0, 1);
    func_002D4240(temp_v0, 0x138D, 0, 1);
    func_002D4240(temp_v0, 0x138E, 1, 1);
    func_002D4240(temp_v0, 0x139C, 0, 1);
    func_002D4240(temp_v0, 0x1435, 0, 1);
    func_002D4480(temp_v0, 0x13B5, 0x138E, 1);
    func_002D6430(temp_v0, D_003E15D4 + 0x13B6, 0, 0x1421, -0x48, -3);
}
