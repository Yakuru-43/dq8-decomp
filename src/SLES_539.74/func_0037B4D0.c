// range: 0x37B4D0 0x37B510
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

M2C_UNK func_003724E0(s32);                         /* extern */

void func_0037B4D0(s32 arg0, s32 arg1) {
    s32 temp_a0;

    if ((arg1 >= 0) && (arg1 < 4)) {
        temp_a0 = *(s32 *) (arg0 + (arg1 * 4));
        if (temp_a0 != 0) {
            func_003724E0(temp_a0);
        }
    }
}
