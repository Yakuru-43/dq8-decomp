// range: 0x2D4310 0x2D43C0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_002D43C0(char *, s32);                     /* extern */
M2C_UNK func_002D4530(char *);                      /* extern */
s32 func_002DDEF0(s32);                             /* extern */
char *func_002DDF10(s32);                           /* extern */

void func_002D4310(char *arg0, s32 arg1, s32 arg2) {
    s32 var_s1;
    char *temp_v0;


    if (!(arg1 != 0)) {
        return;
    }

    var_s1 = M2C_FIELD(arg0, s32 *, 4);
loop_2:
    temp_v0 = func_002DDF10(var_s1);
    if (temp_v0 != NULL) {
        if (func_002D43C0(temp_v0, arg1) != 0) {
            M2C_FIELD(temp_v0, s32 *, 4) = 0;
        }
        var_s1 = func_002DDEF0(var_s1);
        goto loop_2;
    }
    if (arg2 != 0) {
        func_002D4530(arg0);
    }
}
