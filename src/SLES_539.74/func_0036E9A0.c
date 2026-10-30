// range: 0x36E9A0 0x36EA30
#include "common.h"

extern s32 func_0014EA80(s32, ...);
extern s32 func_00100630(s32, void *, s32, s32, s32);
extern s32 func_0014E130(void *, s32);
extern void func_002F6960(void);

void func_0036E9A0(s32 *arg0, void *arg1) {
    s32 tmp;

    tmp = func_0014EA80(0x3E40);
    arg0[3] = func_00100630(tmp, func_002F6960, 0, 0x1F18, 2);

    arg0[0x15D] = func_0014EA80(0x1EA0, arg1);

    arg0[4] = func_0014E130(arg1, 0xA01);
    arg0[7] = func_0014E130(arg1, 0x41);
}
