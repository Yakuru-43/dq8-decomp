// range: 0x3181B0 0x3181D0
#include "common.h"

extern void func_003181F0(void);

void func_003181B0(s32 arg0, s32 arg1, s32 *arg2) {
    *arg2 += 1;
    *(u8 *)((char *)arg2 + 4) = 3;
    func_003181F0();
}
