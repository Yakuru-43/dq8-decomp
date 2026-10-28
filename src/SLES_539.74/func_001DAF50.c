// range: 0x1DAF50 0x1DAFC0
#include "common.h"

extern s32 D_003E0714;
extern s32 D_003E0718;

s32 func_0033A330(s32);
s32 func_0014EA80(s32, s32);
s32 func_00100630(s32, s32, s32, s32, s32);
s32 func_001DAFC0(s32);

void func_001DAF50(s32 arg0, s32 arg1) {
    s32 s0;

    func_0033A330(arg0 + 0x6B34);
    s0 = arg1;
    D_003E0714 = func_00100630(func_0014EA80(0xB90, s0), (s32)func_001DAFC0, 0, 0x5C, 0x20);
    D_003E0718 = func_0014EA80(0x400, s0);
}
