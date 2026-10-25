// range: 0x327620 0x3276A0
// auto: m2c draft, verified byte-exact
// rodata: 0x3D20F0 0x3D212C
#include "common.h"

s32 func_00327620(s32 arg0) {
    s32 var_a0;
    u32 temp_v0;

    var_a0 = arg0;
    temp_v0 = var_a0 & 0xFF;
    switch (temp_v0) {
    case 0:
    case 1:
    case 2:
        var_a0 = 1;
        break;
    case 6:
        var_a0 = 3;
        break;
    case 3:
        var_a0 = 4;
        break;
    case 4:
        var_a0 = 8;
        break;
    case 9:
        var_a0 = 0xB;
        break;
    case 11:
        var_a0 = 0xC;
        break;
    case 12:
        var_a0 = 0xD;
        break;
    case 13:
        var_a0 = 0xE;
        break;
    case 14:
        var_a0 = 0xF;
        break;
    }
    return var_a0;
}
