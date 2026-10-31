// range: 0x14FF20 0x14FFA0
#include "common.h"

s32 func_00150BA0(void);
void func_00150A60(s32, s32);
s32 func_00150030(s32, s32, s32);
s32 func_0014F9B0(s32, s32, s32);

s32 func_0014FF20(s32 arg0, s32 arg1, s32 arg2) {
    s32 ret;
    if (func_00150BA0() == 0) {
        return 0;
    }
    func_00150A60(arg0, arg2);
    if (func_00150030(arg0, arg1, arg2) == 0) {
        return 0;
    }
    ret = func_0014F9B0(arg0, arg1, arg2);
    return ret;
}
