// range: 0x2DB5A0 0x2DB640
#include "common.h"

extern void func_002DB640(s32 arg0, s32 arg1, s16 *arg2, s32 arg3, f32 arg4, f32 arg5);
extern s16 *func_002DE3D0(s32 arg0);

s32 func_002DB5A0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4, f32 arg5) {
    s16 *p;

    p = func_002DE3D0(arg2);

    while (*p != -0x270F) {
        func_002DB640(arg0, arg1, p, arg3, arg4, arg5);
        p += 16;
    }

    return 0;
}
