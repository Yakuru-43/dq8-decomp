// range: 0x1F4FC0 0x1F5050
#include "common.h"

s32 func_001EC050(s32, s32 *);
s32 func_001EC060(s32, s32 *);
M2C_UNK func_001EC990(s32, s32, s32, M2C_UNK, s32);

void func_001F4FC0(s32 arg0, s32 arg1, M2C_UNK arg2) {
    s32 sp3C;
    s32 temp_v0;

    temp_v0 = func_001EC050(arg0 + 0x70, &sp3C);
    if (temp_v0 != 0) {
        if (sp3C > 0) {
            func_001EC990(arg0, temp_v0, sp3C, arg2, 1);
        }
    }
    func_001EC990(arg0, func_001EC060(arg0 + 0x70, &sp3C), sp3C, arg2, 0);
}
