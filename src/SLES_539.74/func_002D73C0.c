// range: 0x2D73C0 0x2D7420
#include "common.h"

extern void func_002D7180(s32 arg0, s32 arg1, f32 *out0, f32 *out1);

void func_002D73C0(s32 arg0, s32 arg1, s32 *out0, s32 *out1) {
    f32 f0;
    f32 f1;

    func_002D7180(arg0, arg1, &f0, &f1);
    *out0 = (s32)f0;
    *out1 = (s32)f1;
}
