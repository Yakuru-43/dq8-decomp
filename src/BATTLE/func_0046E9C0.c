// range: 0x46E9C0 0x46EA70
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

M2C_UNK func_0046E370();           /* extern */
M2C_UNK func_0046EAB0();                    /* extern */

void func_0046E9C0(s32 arg0, M2C_UNK arg1) {
    s32 var_a1;
    s32 var_s1;
    char *temp_a0;

    var_s1 = 0;
    do {
        func_0046E370(arg0, arg1, arg0 + (var_s1 << 5) + 0x2A1C);
        var_s1 += 1;
    } while (var_s1 < 0x18);
    var_a1 = 0;
    do {
        temp_a0= (char *) ( arg0 + (var_a1 << 5));
        var_a1 += 1;
        M2C_FIELD(temp_a0, s32 *, 0x2A1C) = -1;
        M2C_FIELD(temp_a0, s32 *, 0x2A20) = 0;
        M2C_FIELD(temp_a0, s16 *, 0x2A24) = -1;
        M2C_FIELD(temp_a0, s32 *, 0x2A30) = -1;
        M2C_FIELD(temp_a0, s8 *, 0x2A28) = 0;
        M2C_FIELD(temp_a0, s8 *, 0x2A29) = 0;
        M2C_FIELD(temp_a0, s32 *, 0x2A34) = 0;
        M2C_FIELD(temp_a0, s16 *, 0x2A26) = -1;
    } while (var_a1 < 0x18);
    func_0046EAB0(arg0, var_a1);
}
