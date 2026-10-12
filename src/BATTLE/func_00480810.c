// range: 0x480810 0x480860
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

M2C_UNK func_1745A0();             /* extern */

s32 func_00480810(s32 arg0, char *arg1) {
    s32 temp_v0;
    char *temp_v0_2;

    temp_v0 = M2C_FIELD(arg1, s32 *, 0xB4);
    if (temp_v0 == 0) {
        return 1;
    }
    temp_v0_2= (char *) ( temp_v0 + 8);
    if (temp_v0_2 == NULL) {
        return 1;
    }
    func_1745A0(*(s32 *)0x4219F0, M2C_FIELD(temp_v0_2, s32 *, 4), 0);
    return 0;
}
