// range: 0x3181D0 0x3181F0
#include "common.h"

extern void func_003181F0(void);

void func_003181D0(s32 arg0, s32 arg1, s32 *arg2) {
    *arg2 += 1;
    *(u8 *)((char *)arg2 + 4) = 2;
    func_003181F0();
}
