// range: 0x30B1A0 0x30B200
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0030B190(s32);                             /* extern */
M2C_UNK func_00356910(s32, M2C_UNK);                /* extern */

void func_0030B1A0(s32 arg0, void *arg1) {
    s32 temp_a0;

    temp_a0 = M2C_FIELD(arg1, s32 *, 0x130);
    if ((temp_a0 != 0) && (func_0030B190(temp_a0) == 0)) {
        func_00356910(arg0, 1);
        return;
    }
    func_00356910(arg0, 0);
}
