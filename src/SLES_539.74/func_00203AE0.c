// range: 0x203AE0 0x203B10
#include "common.h"

extern u64 func_00203940(s32, s32, s32);
extern u64 func_00259FA0(u64);

void func_00203AE0(s32 arg0, s32 arg1) {
    u64 temp_v0;

    temp_v0 = func_00203940(arg0, arg1, 0);
    func_00259FA0(temp_v0);
}
