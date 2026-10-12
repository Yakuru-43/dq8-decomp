// range: 0x334020 0x3340B0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_0030D7A0(M2C_UNK);                         /* extern */
s32 func_0030D7B0(M2C_UNK);                         /* extern */
s32 func_00329650(M2C_UNK);                         /* extern */
s32 func_003340B0(s32);                             /* extern */

void func_00334020(s32 arg0, char **arg1, M2C_UNK arg2) {
    s32 temp_s1;
    s32 temp_v0;
    s32 temp_v0_2;
    char *temp_s0;

    temp_v0 = func_00329650(arg2);

    if (!(temp_v0 != 0)) {
        return;
    }

    temp_s1 = func_0030D7B0(arg2);
    temp_v0_2 = func_0030D7A0(arg2);
    temp_s0 = *arg1;
    if ((temp_s1 != 0) && (temp_v0_2 != 0) && (temp_s0 != NULL)) {
        M2C_FIELD(temp_s0, s16 *, 0x20) = (s16) (func_003340B0(temp_v0) & 0xFF);
    }
}
