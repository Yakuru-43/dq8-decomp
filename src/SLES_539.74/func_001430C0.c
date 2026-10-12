// range: 0x1430C0 0x1430F0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00156C40(s32);                         /* extern */

void func_001430C0(char *arg0) {
    s32 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s32 *, 0xF20);

    if (!(temp_a0 != 0)) {
        return;
    }

    func_00156C40(temp_a0);
}
