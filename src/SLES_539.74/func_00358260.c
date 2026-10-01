// range: 0x358260 0x358340
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00358260(s32 arg0) {
    s32 var_v0;

    if ((arg0 >= 0x64) && (arg0 < 0x1F4)) {
        var_v0 = 0;
    } else if ((arg0 >= 0x1F4) && (arg0 < 0x259)) {
        var_v0 = 1;
    } else if ((arg0 >= 0x259) && (arg0 < 0x321)) {
        var_v0 = 2;
    } else if ((arg0 >= 0x321) && (arg0 < 0x385)) {
        var_v0 = 3;
    } else if ((arg0 >= 0x385) && (arg0 < 0x3E8)) {
        var_v0 = 4;
    } else if ((arg0 >= 0x3E8) && (arg0 < 0x3EC)) {
        var_v0 = 5;
    } else {
        var_v0 = -1;
    }
    return var_v0;
}
