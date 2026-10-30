// range: 0x3634C0 0x363510
#include "common.h"

extern void func_00131188(char *, s32, s32);

void func_003634C0(char *arg0) {
    func_00131188(arg0, 0, 0x40);
    arg0[0x4C] = 0;
    arg0[0x4D] = 0;
    arg0[0x4E] = 1;
    *(s32 *)(arg0 + 0x54) = 0;
    arg0[0x4F] = 0;
    *(s16 *)(arg0 + 0x52) = -1;
}
