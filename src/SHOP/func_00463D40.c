// range: 0x463D40 0x463E50
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0045F690(M2C_UNK);                     /* extern */
M2C_UNK func_0045F700(M2C_UNK);                     /* extern */
s32 func_2D34C0();                                  /* extern */
M2C_UNK func_2D38E0(s32, s32, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_2D4310(s32, M2C_UNK, M2C_UNK);         /* extern */
M2C_UNK func_2D43D0(s32, M2C_UNK, M2C_UNK);         /* extern */
M2C_UNK func_37EB00(M2C_UNK);                       /* extern */

void func_00463D40(void) {
    s32 temp_s1;
    s32 var_s0;

    temp_s1 = func_2D34C0();
    func_37EB00(0);
    func_0045F700(0);
    func_2D38E0(temp_s1, 0x1797, 0, -1);
    func_0045F690(0);
    func_2D38E0(temp_s1, 0x17A4, 0, -1);
    func_2D38E0(temp_s1, 0x474, 0, -1);
    func_2D38E0(temp_s1, 0x49C, 0, -1);
    func_2D38E0(temp_s1, 0x488, 0, -1);
    func_2D4310(temp_s1, 0x474, 1);
    func_2D43D0(temp_s1, 0x47D, 1);
    var_s0 = 0;
    do {
        func_2D38E0(temp_s1, var_s0 + 0x475, 0, -1);
        var_s0 += 1;
    } while (var_s0 < 4);
    func_2D38E0(temp_s1, 0x47D, 0, -1);
}
