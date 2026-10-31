// range: 0x202530 0x202590
#include "common.h"

void *func_00181420(void);
s32 func_00206080(void *, s32);

s32 func_00202530(void) {
    s32 var_s1;
    s32 var_s0;

    var_s1 = 0;
    var_s0 = 0;
    do {
        if (func_00206080(func_00181420(), var_s0) != 0) {
            var_s1 += 1;
        }
        var_s0 += 1;
    } while (var_s0 < 4);
    return var_s1;
}
