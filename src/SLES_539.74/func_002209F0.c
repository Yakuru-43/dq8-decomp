// range: 0x2209F0 0x220A50
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_002209E0(s32, M2C_UNK);                /* extern */
M2C_UNK func_002218D0(s32);                         /* extern */
M2C_UNK func_00221AC0();                            /* extern */
M2C_UNK func_00221B00(s32, M2C_UNK);                /* extern */
M2C_UNK func_00222370(s32, M2C_UNK);                /* extern */

void func_002209F0(s32 arg0, M2C_UNK arg1) {
    func_00221AC0();
    func_00221B00(arg0, 0);
    func_002218D0(arg0);
    func_00222370(arg0, 0);
    func_002209E0(arg0, arg1);
}
