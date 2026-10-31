// range: 0x2D7420 0x2D7480
#include "common.h"

extern void func_002D7480(s32 arg0, s32 arg1, f32 *out0, f32 *out1);

void func_002D7420(s32 arg0, s32 arg1, s32 *out0, s32 *out1) {
    f32 f0;
    f32 f1;

    func_002D7480(arg0, arg1, &f0, &f1);
    *out0 = (s32)f0;
    *out1 = (s32)f1;
}
