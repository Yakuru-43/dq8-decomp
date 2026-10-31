// range: 0x2D6390 0x2D6430
#include "common.h"

s32 func_002D64C0(s32, s32, s32, s32 *, s32 *);    /* extern */
void func_002D7040(s32, s32, s32, s32, s32, f32);   /* extern */

s32 func_002D6390(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4, s32 arg5,
                  s32 arg6, s32 arg7) {
    s32 out1;
    s32 out2;

    if (func_002D64C0(arg0, arg1, arg2, &out1, &out2) != 0) {
        func_002D7040(arg0, arg3, out1 + arg5, out2 + arg6, arg7, arg4);
        return 1;
    }
    return 0;
}
