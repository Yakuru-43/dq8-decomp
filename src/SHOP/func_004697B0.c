// range: 0x4697B0 0x4698C0
#include "common.h"

extern char *func_0046DDF0(void);
void func_2D4BA0(void *arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_2D53A0(void *arg0, s32 arg1, s32 arg2);
void func_2D6860(void *arg0, s32 arg1, s32 arg2, s32 *arg3, s32 *arg4);
void func_2D6D10(void *arg0, s32 arg1);
void func_2D7040(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5);
void func_2D7060(void *arg0, s32 arg1, s32 arg2);
void func_2D7120(void *arg0, s32 arg1, s32 arg2, s32 arg3);
void func_2D73C0(void *arg0, s32 arg1, s32 *arg2, s32 *arg3);
extern f32 D_003DF388 __attribute__((section(".sdata")));

void func_004697B0(s32 arg0, s32 arg1) {
    char *win;
    s32 count1;
    s32 count2;
    s32 pos1;
    s32 pos2;
    s32 temp_s0;

    win = func_0046DDF0();
    if (win == 0) {
        return;
    }
    func_2D73C0(win, 0x2734, &count1, &count2);
    func_2D6860(win, 0x2737, arg0, &pos1, &pos2);
    func_2D6D10(win, 0x1F6D);
    if (arg1 != 0) {
        func_2D7120(win, 0x1F6D, pos1 - 0x22, pos2 - 2);
    } else {
        func_2D7040(win, 0x1F6D, pos1 - 0x22, pos2 - 2, 0, D_003DF388);
    }
    temp_s0 = func_2D53A0(win, 0x2737, arg0) + 0x18;
    func_2D7060(win, 0x2738, (arg0 * 0x19) + 0xD);
    func_2D4BA0(win, 0x2738, temp_s0, 0);
}
