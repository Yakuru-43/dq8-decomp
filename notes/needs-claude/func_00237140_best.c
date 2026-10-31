// best attempt (switch form), CLASS structural score=9, 104 vs 104 bytes
// remaining diff = missing a1 spill to 0x1C(sp), frame 0x20; see func_00237140.md
// range: 0x237140 0x2371B0
#include "common.h"

M2C_UNK func_00237220();
M2C_UNK func_002373A0();
M2C_UNK func_00237410();

void func_00237140(void *arg0, s32 arg1, void *arg2, s32 arg3, s32 arg4) {
    u16 kind = M2C_FIELD(arg2, u16 *, 0x38) & 0x4A;

    switch (kind) {
    case 0x40:
        func_00237410(arg0, arg1, arg2, arg3, arg4, 0);
        break;
    case 8:
        func_00237220(arg0, arg1, arg2, arg3, arg4, 0);
        break;
    default:
        func_002373A0(arg0, arg1, arg2, arg3, arg4, 0);
        break;
    }
}
