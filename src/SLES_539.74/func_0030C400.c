// range: 0x30C400 0x30C440
#include "common.h"

s32 func_00296F60(s32);
M2C_UNK func_00356910(s32, s64);

void func_0030C400(s32 arg0, s32 arg1) {
    func_00356910(arg0, func_00296F60(M2C_FIELD(arg1, s32 *, 0x158)));
}
