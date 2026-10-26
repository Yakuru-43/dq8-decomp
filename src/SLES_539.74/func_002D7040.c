// range: 0x2D7040 0x2D7060
#include "common.h"

void func_002D6F10(s32, s32, s32, s32, s32, f32, f32, s32, s32, s32); /* extern */

/* tail call: hand the float through to both coords, flags cleared */
void func_002D7040(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5) {
    func_002D6F10(arg0, arg1, arg2, arg3, arg4, arg5, arg5, 0, 0, 0);
}
