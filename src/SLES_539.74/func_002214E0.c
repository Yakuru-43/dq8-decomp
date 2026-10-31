// range: 0x2214E0 0x221570
#include "common.h"

extern f32 D_003DF46C;
void func_002E6780(s32, s32, s32);

void func_002214E0(s32 arg0, s32 arg1, f32 arg2) {
    if (arg2 <= 0.0f) {
        func_002E6780(arg0, arg1, 0x80333366);
    } else if (arg2 <= D_003DF46C) {
        func_002E6780(arg0, arg1, 0x80324B73);
    } else if (arg2 <= 0.25f) {
        func_002E6780(arg0, arg1, 0x80326480);
    } else {
        func_002E6780(arg0, arg1, 0);
    }
}
