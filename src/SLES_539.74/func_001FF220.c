// range: 0x1FF220 0x1FF270
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_001FF220(char *arg0) {
    s32 var_a1;
    char *temp_v1;

    M2C_FIELD(arg0, s32 *, 0x118C) = 0;
    var_a1 = 0;
    M2C_FIELD(arg0, s8 *, 0x1190) = 0;
    M2C_FIELD(arg0, s32 *, 0x11A0) = 0;
    M2C_FIELD(arg0, s32 *, 0x1754) = 0;
    M2C_FIELD(arg0, s32 *, 0x1758) = 0;
    M2C_FIELD(arg0, s32 *, 0x175C) = 0;
    M2C_FIELD(arg0, s32 *, 0x1760) = 0;
    M2C_FIELD(arg0, s32 *, 0x1764) = 0;
    do {
        temp_v1 = arg0 + (var_a1 * 4);
        var_a1 += 1;
        M2C_FIELD(temp_v1, s32 *, 0x1130) = 0;
    } while (var_a1 < 0x17);
}
