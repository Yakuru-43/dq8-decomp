// range: 0x2EC5D0 0x2EC670
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_002EC5D0(char *arg0) {
    s32 var_a1;
    s32 var_a2;
    char *temp_v1;
    char *temp_v1_2;

    M2C_FIELD(arg0, s32 *, 0x194) = 0;
    var_a1 = 0;
    M2C_FIELD(arg0, s32 *, 0x190) = 0;
    M2C_FIELD(arg0, s8 *, 0x1659) = 0;
    M2C_FIELD(arg0, s32 *, 0x1660) = 0;
    M2C_FIELD(arg0, s8 *, 0x18E) = 0;
    M2C_FIELD(arg0, s32 *, 0x11BC) = 0;
    M2C_FIELD(arg0, s32 *, 0x10C) = 0;
    M2C_FIELD(arg0, s32 *, 0x110) = 0;
    do {
        temp_v1 = arg0 + (var_a1 * 4);
        var_a1 += 1;
        M2C_FIELD(temp_v1, s32 *, 0x114) = 0;
    } while (var_a1 < 0x10);
    M2C_FIELD(arg0, s32 *, 0x154) = 0;
    var_a2 = 0;
    do {
        if ((var_a2 >= 0) && (var_a2 < 0x14)) {
            M2C_FIELD((arg0 + (var_a2 * 4)), s32 *, 0x1DD8) = 0;
        }
        temp_v1_2 = arg0 + (var_a2 * 4);
        var_a2 += 1;
        M2C_FIELD(temp_v1_2, s32 *, 0x1E28) = -1;
    } while (var_a2 < 0x14);
    M2C_FIELD(arg0, s8 *, 0x11D5) = 1;
    M2C_FIELD(arg0, s32 *, 0x11D8) = 0;
}
