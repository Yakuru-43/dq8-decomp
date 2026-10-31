// range: 0x318150 0x318170
#include "common.h"

extern void func_003181F0(void);

void func_00318150(s32 arg0, s32 arg1, s32 *arg2) {
    *arg2 += 1;
    ((u8 *)arg2)[4] = 7;
    func_003181F0();
}
