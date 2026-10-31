// range: 0x318170 0x318190
#include "common.h"

M2C_UNK func_003181F0();

void func_00318170(s32 arg0, s32 arg1, s32 *arg2) {
    *arg2 += 1;
    *(u8 *)((char *)arg2 + 4) = 6;
    func_003181F0();
}
