// range: 0x310870 0x3108A0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_001EA0A0(s32);                         /* extern */

void func_00310870(char *arg0) {
    s32 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s32 *, 4);

    if (!(temp_a0 != 0)) {
        return;
    }

    func_001EA0A0(temp_a0);
}
