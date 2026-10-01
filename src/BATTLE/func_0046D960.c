// range: 0x46D960 0x46DAF0
// auto: m2c draft, verified byte-exact
// flags: -O4
#include "common.h"

M2C_UNK func_131188(s32, M2C_UNK, M2C_UNK);         /* extern */
M2C_UNK func_14DF10(char *, s32, M2C_UNK);          /* extern */
M2C_UNK func_14DF80(char *);                        /* extern */
s32 func_14E240(M2C_UNK, M2C_UNK);                  /* extern */
M2C_UNK func_14E860(char *);                        /* extern */

void func_0046D960(char *arg0, M2C_UNK arg1) {
    s32 var_s0;
    s32 var_s1;
    char *temp_s0;
    char *temp_s1;
    char *temp_s4;
    char *temp_v1;
    char *temp_v1_2;

    var_s1 = 0;
    do {
        temp_s0 = arg0 + (var_s1 * 0x58);
        func_14E860(temp_s0);
        func_14DF80(temp_s0);
        func_14DF10(temp_s0, func_14E240(arg1, 0x141), 0x140);
        temp_v1 = arg0 + (var_s1 * 4);
        M2C_FIELD(temp_v1, s32 *, 0xA50) = -1;
        M2C_FIELD(temp_v1, s32 *, 0xAC8) = (s32) M2C_FIELD(temp_s0, s32 *, 0x28);
        func_131188(M2C_FIELD(temp_v1, s32 *, 0xAC8), 0, 0x1400);
        var_s1 += 1;
    } while (var_s1 < 0x1E);
    var_s0 = 0;
    do {
        temp_s1 = arg0 + (var_s0 * 0x58);
        temp_s4 = temp_s1 + 0xB9C;
        func_14E860(temp_s4);
        func_14DF80(temp_s4);
        func_14DF10(temp_s4, func_14E240(arg1, 0x281), 0x280);
        temp_v1_2 = arg0 + (var_s0 * 4);
        M2C_FIELD(temp_v1_2, s32 *, 0xCFC) = (s32) M2C_FIELD(temp_s1, s32 *, 0xBC4);
        func_131188(M2C_FIELD(temp_v1_2, s32 *, 0xCFC), 0, 0x2800);
        var_s0 += 1;
    } while (var_s0 < 4);
    func_14E860(arg0 + 0xB40);
    func_14DF80(arg0 + 0xB40);
    func_14DF10(arg0 + 0xB40, func_14E240(arg1, 0x1401), 0x1400);
    M2C_FIELD(arg0, s32 *, 0xB98) = (s32) M2C_FIELD(arg0, s32 *, 0xB68);
    func_131188(M2C_FIELD(arg0, s32 *, 0xB98), 0, 0x14000);
}
