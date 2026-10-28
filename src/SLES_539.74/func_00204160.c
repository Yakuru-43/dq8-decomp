// range: 0x204160 0x204200
#include "common.h"

s32 func_00201DB0(s32);
s32 func_00206080(char *, s32);
s32 func_00206D70(s32, s32, M2C_UNK, s32);

s32 func_00204160(s32 arg0, M2C_UNK arg1, s32 arg2) {
    s32 var_s0;
    s32 var_s1;
    s32 var_s2;

    var_s0 = arg2;
    var_s1 = func_00201DB0(arg0);
    var_s2 = 0;
    do {
        if ((var_s2 >= 4) || (func_00206080((char *) arg0, var_s2) != 0)) {
            var_s0 = func_00206D70(var_s1, var_s2, arg1, var_s0);
        }
        var_s2 += 1;
    } while (var_s2 < 5);
    return 0;
}
