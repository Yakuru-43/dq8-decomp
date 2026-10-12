// range: 0x143350 0x143380
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00157350(s32);                         /* extern */

void func_00143350(char *arg0) {
    s32 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s32 *, 0xF20);

    if (!(temp_a0 != 0)) {
        return;
    }

    func_00157350(temp_a0);
}
