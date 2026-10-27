// range: 0x19D4A0 0x19D570
#include "common.h"

M2C_UNK func_001526D0(char *);                      /* extern */

void func_0019D4A0(char *arg0) {
    s32 var_a0;
    s32 var_s0;
    char *temp_a0;
    char *temp_s2;
    char *temp_v1;

    var_s0 = 0;
    do {
        temp_s2 = arg0 + (var_s0 * 0x1C0);
        func_001526D0(temp_s2 + 0x10);
        func_001526D0(temp_s2 + 0x730);
        func_001526D0(temp_s2 + 0xE50);
        temp_a0 = arg0 + (var_s0 * 4);
        var_s0 += 1;
        M2C_FIELD(temp_a0, s32 *, 0xE30) = 0;
        M2C_FIELD(temp_a0, s32 *, 0x710) = 0;
        M2C_FIELD(temp_a0, s32 *, 0xE40) = 0;
        M2C_FIELD(temp_a0, s32 *, 0x720) = 0;
        M2C_FIELD(temp_a0, s32 *, 0x1550) = -1;
    } while (var_s0 < 4);
    var_a0 = 0;
    do {
        temp_v1 = arg0 + (var_a0 * 8);
        var_a0 += 1;
        M2C_FIELD(temp_v1, s32 *, 0x1728) = 0;
        M2C_FIELD(temp_v1, s32 *, 0x172C) = 0;
    } while (var_a0 < 0x10);
    func_001526D0(arg0 + 0x1560);
    M2C_FIELD(arg0, s32 *, 0x1720) = 0;
    M2C_FIELD(arg0, s32 *, 0x1724) = 0x457A0000;
    M2C_FIELD(arg0, s32 *, 0) = 1;
}
