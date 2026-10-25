// range: 0x3276A0 0x327720
// auto: m2c draft, verified byte-exact
// rodata: 0x3D2130 0x3D2170
#include "common.h"

s32 func_003276A0(s32 arg0) {
    s32 var_a0;
    u32 temp_v0;

    var_a0 = arg0;
    temp_v0 = var_a0 & 0xFF;
    switch (temp_v0) {
    case 1:
        var_a0 = 0;
        break;
    case 0:
        var_a0 = 2;
        break;
    case 5:
    case 8:
        var_a0 = 4;
        break;
    case 4:
        var_a0 = 3;
        break;
    case 3:
        var_a0 = 6;
        break;
    case 15:
        var_a0 = 0xE;
        break;
    case 14:
        var_a0 = 0xD;
        break;
    case 13:
        var_a0 = 0xC;
        break;
    case 12:
        var_a0 = 0xB;
        break;
    case 11:
        var_a0 = 9;
        break;
    }
    return var_a0;
}
