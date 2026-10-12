// range: 0x476E80 0x476EB0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_1EA0A0(s32);                           /* extern */

void func_00476E80(char *arg0) {
    s32 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s32 *, 0x6C);

    if (!(temp_a0 != 0)) {
        return;
    }

    func_1EA0A0(temp_a0);
}
