// best C for func_002CB270 (164 B vs 160 B, CLASS structural score=30); see
// notes/needs-claude/func_002CB270.md for the diff and what was tried.
// range: 0x2CB270 0x2CB310
#include "common.h"

void *func_00359CF0(M2C_UNK *, s32);                /* extern */
s32 func_002B0950(M2C_UNK *, s32);                  /* extern */
void *func_0016D5B0(void *, s32);                   /* extern */
extern M2C_UNK D_00421AD0 __attribute__((section(".data")));
extern M2C_UNK D_0042EA80 __attribute__((section(".data")));

f32 func_002CB270(void *arg0, s32 arg1) {
    u32 *work = (u32 *)0x41000000;
    f32 scale;

    if (func_00359CF0(&D_00421AD0, arg1) == 0) {
        return 8.0f;
    }
    if (work[8] != 0) {
        scale = (f32)func_002B0950(&D_0042EA80, work[0]);
    } else {
        if (func_0016D5B0(arg0, arg1) == 0) {
            return 10.0f;
        }
        scale = *(f32 *)0x41204C8;
    }
    return 2.0f * scale;
}
