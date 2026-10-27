// range: 0x473A10 0x473AF0
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

M2C_UNK func_131188();         /* extern */

s32 func_00473A10(s32 arg0, s32 arg1, char *arg2) {
    s32 var_s1;
    char *temp_a0;
    char *temp_s5;
    char *temp_v1;

    temp_v1= (char *) ( arg0 + (arg1 * 4));
    if (M2C_FIELD(temp_v1, char **, 0) != NULL) {
        return 0;
    }
    M2C_FIELD(temp_v1, char **, 0) = arg2;
    M2C_FIELD(temp_v1, s32 *, 0x1D00) = 0;
    M2C_FIELD(temp_v1, s32 *, 0x1E00) = 0;
    M2C_FIELD(temp_v1, s32 *, 0x1F00) = 0;
    var_s1 = 0;
    do {
        temp_s5= (char *) ( arg0 + (arg1 * 0x1400) + (var_s1 * 0xA0));
        func_131188(temp_s5 + 0x2000, 0, 0xA0);
        var_s1 += 1;
        M2C_FIELD(temp_s5, s32 *, 0x2000) = 0;
    } while (var_s1 < 0x20);
    temp_a0= (char *) ( arg0 + (arg1 * 0x10));
    M2C_FIELD(temp_a0, s128 *, 0x100)= (s128) M2C_FIELD(arg2, s128 *, 0x180);
    M2C_FIELD(temp_a0, s128 *, 0x500)= (s128) M2C_FIELD(arg2, s128 *, 0x190);
    return 1;
}
