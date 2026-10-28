// range: 0x1E6520 0x1E6570
#include "common.h"

extern void func_001E6190(void *arg0, ...);

void func_001E6520(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                   s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8)
{
    s32 buf[4];

    buf[0] = arg1;
    buf[1] = arg0;
    buf[2] = 0;
    buf[3] = 0;

    func_001E6190(buf, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}
