// range: 0x14C290 0x14C310
#include "common.h"

extern void func_00131188(char *, s32, s32);
extern void func_0013E080(char *);

void func_0014C290(char *arg0) {
    func_00131188(arg0, 0, 0x60);
    func_0013E080(arg0);
    *(s128 *)(arg0 + 0x10) = 0;
    *(s128 *)(arg0 + 0x20) = 0;
    *(s32 *)(arg0 + 0x40) = 0xA;
    *(s32 *)(arg0 + 0x44) = 0x3A;
    *(s32 *)(arg0 + 0x48) = 7;
    arg0[0x4C] = 1;
    arg0[0x4D] = 5;
    arg0[0x4E] = 1;
    arg0[0x4F] = 0;
    arg0[0x50] = 2;
    arg0[0x51] = 0;
    arg0[0x52] = 1;
    arg0[0x53] = 0;
}
