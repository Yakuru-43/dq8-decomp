// range: 0x3180F0 0x318110
#include "common.h"

extern void func_003181F0(void);

void func_003180F0(s32 arg0, s32 arg1, u8 *arg2) {
    *(s32 *)arg2 += 1;
    arg2[4] = 12;
    func_003181F0();
}
