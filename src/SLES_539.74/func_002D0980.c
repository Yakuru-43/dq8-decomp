// range: 0x2D0980 0x2D0A70
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_002D34C0();                                /* extern */
M2C_UNK func_002D4240(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_002D4B40(s32, M2C_UNK);                /* extern */

void func_002D0980(void) {
    s32 temp_v0;

    temp_v0 = func_002D34C0();
    func_002D4240(temp_v0, 0x1421, 0, 1);
    func_002D4240(temp_v0, 0x1422, 0, 1);
    func_002D4240(temp_v0, 0x1423, 0, 1);
    func_002D4240(temp_v0, 0x1424, 0, 1);
    func_002D4240(temp_v0, 0x1425, 0, 1);
    func_002D4240(temp_v0, 0x1426, 0, 1);
    func_002D4B40(temp_v0, 0x1421);
    func_002D4B40(temp_v0, 0x1422);
    func_002D4B40(temp_v0, 0x1423);
    func_002D4B40(temp_v0, 0x1424);
    func_002D4B40(temp_v0, 0x1425);
    func_002D4B40(temp_v0, 0x1426);
}
