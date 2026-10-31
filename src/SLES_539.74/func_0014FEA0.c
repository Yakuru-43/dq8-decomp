// range: 0x14FEA0 0x14FF20
#include "common.h"

s32 func_00150BA0(void);
void func_00150A60(s32, u32);
s32 func_00150030(s32, u32, u32);
s32 func_0014F060(s32, u32, u32);

s32 func_0014FEA0(s32 arg0, u32 arg1, u32 arg2) {
    if (func_00150BA0() == 0) {
        return 0;
    }
    func_00150A60(arg0, arg2);
    if (func_00150030(arg0, arg1, arg2) == 0) {
        return 0;
    }
    return func_0014F060(arg0, arg1, arg2);
}
