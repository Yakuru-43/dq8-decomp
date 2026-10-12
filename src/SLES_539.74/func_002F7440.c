// range: 0x2F7440 0x2F74E0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00131188(char *, M2C_UNK, M2C_UNK);    /* extern */

void func_002F7440(char *arg0) {
    s32 var_a0;


    if (!(M2C_FIELD(arg0, u8 *, 0x1664) != 0)) {
        return;
    }

    M2C_FIELD(arg0, s8 *, 0x18D) = 0;
    M2C_FIELD(arg0, s32 *, 0x11C4) = -1;
    M2C_FIELD(arg0, s32 *, 0x11C8) = 0;
    M2C_FIELD(arg0, s8 *, 0x165A) = 0;
    func_00131188(arg0 + 0x198, 0, 0x1000);
    var_a0 = 0;
    do {
        if ((var_a0 >= 0) && (var_a0 < 0x200)) {
            M2C_FIELD((arg0 + (var_a0 * 8)), s8 *, 0x19E) = 0;
        }
        var_a0 += 1;
    } while (var_a0 < 0x200);
    M2C_FIELD(arg0, s32 *, 0x1198) = 0;
    M2C_FIELD(arg0, s32 *, 0x119C) = 0;
    M2C_FIELD(arg0, s32 *, 0x11A0) = 0;
    M2C_FIELD(arg0, s32 *, 0x11A4) = 0;
    M2C_FIELD(arg0, s32 *, 0x11A8) = 0;
    M2C_FIELD(arg0, s32 *, 0x11AC) = 0;
}
