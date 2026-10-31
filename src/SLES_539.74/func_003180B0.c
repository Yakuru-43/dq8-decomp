// range: 0x3180B0 0x3180D0
#include "common.h"

extern void func_003181F0(void);

void func_003180B0(s32 arg0, s32 arg1, s32 *arg2) {
    *arg2 += 1;
    *(u8 *)((char *)arg2 + 4) = 0x13;
    func_003181F0();
}
