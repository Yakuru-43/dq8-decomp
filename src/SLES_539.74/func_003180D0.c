// range: 0x3180D0 0x3180F0
#include "common.h"

M2C_UNK func_003181F0();

void func_003180D0(s32 arg0, s32 arg1, s32 *arg2) {
    *arg2 += 1;
    *(u8 *)((char *)arg2 + 4) = 0x10;
    func_003181F0();
}
