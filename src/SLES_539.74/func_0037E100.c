// range: 0x37E100 0x37E170
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_002D34C0();                                /* extern */
M2C_UNK func_002D38E0(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_0037E100(void) {
    s32 temp_v0;

    temp_v0 = func_002D34C0();
    func_002D38E0(temp_v0, 0x186E2, 0, -1);
    func_002D38E0(temp_v0, 0x186E5, 0, -1);
    func_002D38E0(temp_v0, 0x186E3, 0, -1);
}
