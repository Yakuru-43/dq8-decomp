// range: 0x30D5A0 0x30D600
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

M2C_UNK func_0030D180(char *, s64 *);               /* extern */

s32 func_0030D5A0(s32 *arg0, s64 arg1) {
    s64 sp28;
    s32 temp_v1;

    sp28 = arg1;
    temp_v1 = *arg0;
    if (temp_v1 >= 0x20) {
        return 0;
    }
    func_0030D180((char *) arg0 + (temp_v1 * 8) + 4, &sp28);
    *arg0 += 1;
    return 1;
}
