// range: 0x381B80 0x381BF0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_002D34C0();                                /* extern */
M2C_UNK func_002D4240(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_002D4B40(s32, M2C_UNK);                /* extern */
M2C_UNK func_002D6E40(s32, M2C_UNK, M2C_UNK);       /* extern */

void func_00381B80(void) {
    s32 temp_v0;

    temp_v0 = func_002D34C0();
    func_002D4240(temp_v0, 0x1438, 0, 1);
    func_002D4B40(temp_v0, 0x1421);
    func_002D6E40(temp_v0, 0x138C, 1);
    func_002D6E40(temp_v0, 0x138D, 1);
}
