// range: 0x30ACC0 0x30AD20
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0030AD20(s32);                             /* extern */
M2C_UNK func_00356910(s32, M2C_UNK);                /* extern */

void func_0030ACC0(s32 arg0, void *arg1) {
    s32 temp_a0;

    temp_a0 = M2C_FIELD(arg1, s32 *, 0x124);
    if ((temp_a0 != 0) && (func_0030AD20(temp_a0) == 1)) {
        func_00356910(arg0, 1);
        return;
    }
    func_00356910(arg0, 0);
}
