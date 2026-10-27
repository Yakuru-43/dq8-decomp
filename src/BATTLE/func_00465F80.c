// range: 0x465F80 0x465FF0
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_00467060(char *, s32);
void func_00465F80(char *arg0, s32 arg1) {
    s32 var_s0;

    M2C_FIELD(arg0, s32 *, 0x3960) = arg1;
    var_s0 = 0;
    do {
        func_00467060(arg0 + (var_s0 * 0x260), arg1);
        var_s0 += 1;
    } while (var_s0 < 0x18);
}
