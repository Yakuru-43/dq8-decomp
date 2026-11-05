// range: 0x473920 0x473A10
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

M2C_UNK func_131188();         /* extern */
M2C_UNK func_14A7E0();         /* extern */
M2C_UNK func_14A810();         /* extern */

s32 func_00473920(char *arg0, s32 arg1, char *arg2) {
    s32 var_s2;
    s32 temp_s1;
    s32 off;
    char *temp_s0;
    char *temp_s5;
    char *temp_v1;

    off = arg1 * 4;
    temp_v1 = (char *) (off + (s32) arg0);
    if (M2C_FIELD(temp_v1, char **, 0x80) != NULL) {
        return 0;
    }
    temp_s1 = arg1 + 0x20;
    M2C_FIELD(temp_v1, char **, 0x80) = arg2;
    off = temp_s1 * 4;
    temp_s0 = (char *) (off + (s32) arg0);
    M2C_FIELD(temp_s0, s32 *, 0x1D00) = 0;
    M2C_FIELD(temp_s0, s32 *, 0x1E00) = 0;
    M2C_FIELD(temp_s0, s32 *, 0x1F00) = 0;
    var_s2 = 0;
    do {
        temp_s5 = arg0 + (temp_s1 * 0x1400) + (var_s2 * 0xA0);
        func_131188(temp_s5 + 0x2000, 0, 0xA0);
        var_s2 += 1;
        M2C_FIELD(temp_s5, s32 *, 0x2000) = 0;
    } while (var_s2 < 0x20);
    temp_s0 = arg0 + (temp_s1 * 0x10);
    func_14A810(arg2, temp_s0 + 0x100);
    func_14A7E0(arg2, temp_s0 + 0x500);
    return 1;
}
