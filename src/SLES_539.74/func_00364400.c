// range: 0x364400 0x364480
#include "common.h"

extern s32 func_003643C0(void);
extern void func_001340C0(s32, void *);
extern void func_0036CD90(s32, s32, s32, s32, s32, s32, s32, s32, s64, s64);

extern u8 D_003D4C50[];

void func_00364400(s32 arg0, s32 *arg1) {
    s32 temp_v0;
    s64 stack0;
    s64 stack1;

    temp_v0 = func_003643C0();
    func_001340C0(temp_v0, D_003D4C50);

    stack0 = 1;
    stack1 = 0;

    func_0036CD90(arg0, arg1[1], arg1[4], 0, 0, 1, temp_v0, 0, stack0, stack1);
}
