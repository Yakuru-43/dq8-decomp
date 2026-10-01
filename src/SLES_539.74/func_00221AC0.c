// range: 0x221AC0 0x221B00
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00221900(s32);                         /* extern */
M2C_UNK func_00221950(s32);                         /* extern */
M2C_UNK func_002219A0();                            /* extern */

void func_00221AC0(s32 arg0) {
    func_002219A0();
    func_00221950(arg0);
    func_00221900(arg0);
}
