// range: 0x207330 0x2073D0
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

M2C_UNK func_00131188(s32, M2C_UNK, M2C_UNK);       /* extern */
s32 func_002072F0();                                /* extern */

void func_00207330(s32 arg0, s32 arg1) {
    s32 var_a2;
    char *temp_v1;

    if (4 != arg1) {
        func_00131188(func_002072F0(), 0, 0x30);
        var_a2 = 0;
        do {
            temp_v1= (char *) ( arg0 + (arg1 * 0xA) + (var_a2 * 2));
            var_a2 += 1;
            M2C_FIELD(temp_v1, s16 *, 0x840) = -1;
        } while (var_a2 < 4);
    } else {
        func_00131188(arg0 + 0xC0, 0, 0x780);
    }
}
