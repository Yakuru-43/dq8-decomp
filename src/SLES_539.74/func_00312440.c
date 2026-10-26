// range: 0x312440 0x312490
#include "common.h"

s16 func_00202A80(s32, s32, void *, s32, s32, s32);

void func_00312440(s16 *obj, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    obj[1] = arg3;
    obj[0] = arg1;
    obj[2] = func_00202A80(arg1, arg2, obj + 6, 0x80, arg3, arg4);
    obj[3] = 0;
}
