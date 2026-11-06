// range: 0x45F140 0x45F1D0
#include "common.h"

s32 func_004630D0(void);                           /* extern */
s32 func_377070(s32);                              /* extern */
M2C_UNK func_3772B0(s32);                          /* extern */
void *func_201CC0(void);                           /* extern */
void *func_201CD0(void);                           /* extern */
M2C_UNK func_372E60(void *, s32, s32);              /* extern */
M2C_UNK func_370C00(void *, M2C_UNK *, s32);        /* extern */

extern M2C_UNK D_00478F18 __attribute__((section(".data")));

s32 func_0045F140(s32 arg0, s32 arg1) {
    void *p;
    void *q;
    s32 r;

    if (arg1 != 0) {
        r = func_004630D0();
        func_3772B0(r - 0x171);
        return 0;
    } else {
        if (func_377070(arg0) != 0) {
            p = func_201CC0();
            func_372E60(p, 1, 0);
            q = func_201CD0();
            func_370C00(q, &D_00478F18, 0);
        }
        return 0;
    }
}
