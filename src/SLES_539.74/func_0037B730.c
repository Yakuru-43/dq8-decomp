// range: 0x37B730 0x37B770
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

M2C_UNK func_00372850();                /* extern */

void func_0037B730(s32 arg0, s32 arg1, M2C_UNK arg2) {
    s32 temp_a0;

    if ((arg1 >= 0) && (arg1 < 4)) {
        temp_a0 = *(s32 *) (arg0 + (arg1 * 4));
        if (temp_a0 != 0) {
            func_00372850(temp_a0, arg2);
        }
    }
}
