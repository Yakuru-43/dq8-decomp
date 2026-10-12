// range: 0x46E290 0x46E330
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

M2C_UNK func_0046E370();               /* extern */

void func_0046E290(s32 arg0, s32 arg1) {
    s32 var_a2;
    s32 var_s1;
    char *temp_a1;

    var_s1 = 0;
    do {
        func_0046E370(arg0, arg1, arg0 + (var_s1 << 5) + 0x2A1C);
        var_s1 += 1;
    } while (var_s1 < 0x18);
    var_a2 = 0;
    do {
        temp_a1= (char *) ( arg0 + (var_a2 << 5));
        var_a2 += 1;
        M2C_FIELD(temp_a1, s32 *, 0x2A1C) = -1;
        M2C_FIELD(temp_a1, s32 *, 0x2A20) = 0;
        M2C_FIELD(temp_a1, s16 *, 0x2A24) = -1;
        M2C_FIELD(temp_a1, s32 *, 0x2A30) = -1;
        M2C_FIELD(temp_a1, s8 *, 0x2A28) = 0;
        M2C_FIELD(temp_a1, s8 *, 0x2A29) = 0;
        M2C_FIELD(temp_a1, s32 *, 0x2A34) = 0;
        M2C_FIELD(temp_a1, s16 *, 0x2A26) = -1;
    } while (var_a2 < 0x18);
}
