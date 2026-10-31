// range: 0x2B0790 0x2B0810
#include "common.h"

extern void func_0014E030(void *);
extern s32 func_0014E130(void *, s32);
extern s32 func_0014EA80(s32, void *);
extern s32 func_00100630(s32, void *, s32, s32, s32);
extern void func_002B0810(void);

void func_002B0790(s32 *arg0, void *arg1) {
    s32 tmp;
    func_0014E030(arg1);
    *arg0 = func_0014E130(arg1, 0x1400);
    func_0014E030(arg1);
    tmp = func_0014EA80(0x1078, arg1);
    arg0[5] = func_00100630(tmp, func_002B0810, 0, 6, 0x2BC);
    arg0[4] = 0;
}
