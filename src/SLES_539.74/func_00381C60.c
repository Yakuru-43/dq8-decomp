// range: 0x381C60 0x381D10
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_002D34C0();                                /* extern */
M2C_UNK func_002D4240(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_002D4B40(s32, M2C_UNK);                /* extern */
M2C_UNK func_002D6E40(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_003125C0();                            /* extern */
extern s8 D_003E15C4;

void func_00381C60(void) {
    s32 temp_a0;
    s32 temp_s0;

    temp_s0 = func_002D34C0();
    temp_a0 = temp_s0;
    D_003E15C4 = 0;
    func_002D4240(temp_a0, 0x138C, 1, 1);
    func_002D4240(temp_s0, 0x138D, 1, 0);
    func_003125C0();
    func_002D4240(temp_s0, 0x138E, 0, 1);
    func_002D4240(temp_s0, 0x1399, 0, 1);
    func_002D4240(temp_s0, 0x1422, 0, 1);
    func_002D6E40(temp_s0, 0x138E, 1);
    func_002D4B40(temp_s0, 0x1421);
}
