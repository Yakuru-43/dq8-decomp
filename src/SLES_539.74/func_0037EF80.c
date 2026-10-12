// range: 0x37EF80 0x37EFD0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_002D34C0();                                /* extern */
M2C_UNK func_002D3BC0(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_002D3F80(s32, M2C_UNK, M2C_UNK);       /* extern */

void func_0037EF80(void) {
    s32 temp_v0;

    temp_v0 = func_002D34C0();

    if (!(temp_v0 != 0)) {
        return;
    }

    func_002D3F80(temp_v0, 0x18703, 1);
    func_002D3BC0(temp_v0, 2, 1);
}
