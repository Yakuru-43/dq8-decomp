// range: 0x2D6710 0x2D67B0
// best attempt: CLASS reorder-only score=2 (mov.s f12/f20 vs daddu t0/s0 swapped, see .md)
#include "common.h"

s32 func_002D6860(s32, s32, s32, s32 *, s32 *, f32); /* extern */
void func_002D7040(s32, s32, s32, s32, s32, f32); /* extern */

s32 func_002D6710(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5,
                  s32 arg6, f32 arg7) {
    s32 out1;
    s32 out2;

    if (func_002D6860(arg0, arg1, arg2, &out1, &out2, arg7) != 0) {
        func_002D7040(arg0, arg3, out1 + arg4, out2 + arg5, arg6, arg7);
        return 1;
    }
    return 0;
}
