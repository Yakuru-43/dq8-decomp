// range: 0x1E6710 0x1E6750
#include "common.h"

extern void func_001E6570(void *arg0, s32 arg1, s32 arg2, s32 arg3);

void func_001E6710(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                   s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8)
{
    s32 buf[4];

    buf[0] = arg1;
    buf[1] = arg0;
    buf[2] = 0;
    buf[3] = 0;

    func_001E6570(buf, arg2, arg3, arg4);
}
