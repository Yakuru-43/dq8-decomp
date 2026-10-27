// range: 0x475620 0x4756C0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_131188(char *, M2C_UNK, M2C_UNK);      /* extern */

void func_00475620(char *arg0) {
    s32 var_s0;
    char *temp_v1;

    M2C_FIELD(arg0, s32 *, 4) = 0;
    var_s0 = 0;
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 0x80) = 0;
    M2C_FIELD(arg0, s32 *, 0x84) = 0;
    M2C_FIELD(arg0, s32 *, 0x88) = 0;
    M2C_FIELD(arg0, s32 *, 0xC90) = 0;
    M2C_FIELD(arg0, s32 *, 0xC94) = 0;
    M2C_FIELD(arg0, s32 *, 0xC98) = 0;
    M2C_FIELD(arg0, s32 *, 0xC9C) = 0;
    do {
        temp_v1 = arg0 + (var_s0 * 0x60);
        M2C_FIELD(temp_v1, s32 *, 0x90) = 0;
        M2C_FIELD(temp_v1, s32 *, 0xC0) = -1;
        M2C_FIELD(temp_v1, s32 *, 0xE4) = 0;
        M2C_FIELD(temp_v1, s32 *, 0xE8) = 0;
        func_131188(temp_v1 + 0xC4, 0, 0x20);
        var_s0 += 1;
    } while (var_s0 < 0x20);
}
