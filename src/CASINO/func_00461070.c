// range: 0x461070 0x4610B0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_20C8C0(s32, M2C_UNK, M2C_UNK);         /* extern */
M2C_UNK func_3056A0();                              /* extern */

void func_00461070(char *arg0) {
    s32 temp_s0;

    temp_s0 = M2C_FIELD(arg0, s32 *, 0x14);

    if (!(temp_s0 != 0)) {
        return;
    }

    func_3056A0();
    func_20C8C0(temp_s0, 0, -1);
}
