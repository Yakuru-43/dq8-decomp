// range: 0x300C00 0x300C70
#include "common.h"

s32 func_001814D0(void);                /* extern */
s32 func_00308AD0(s32, s32);             /* extern */
char *func_00181420(void);               /* extern */
s32 func_00203E20(char *, s32);          /* extern */

s32 func_00300C00(void) {
    s32 ret;

    ret = 1;
    if (func_00308AD0(func_001814D0() + 0x470, 0x20) == 0) {
        if (0 < func_00203E20(func_00181420(), 0x15F)) {
            ret = 0;
        }
    }
    return ret;
}
