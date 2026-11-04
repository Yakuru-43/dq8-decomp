// range: 0x464530 0x464690
#include "common.h"

extern void *func_2D34C0(void);
void func_2D38E0(void *arg0, s32 arg1, s32 arg2, s32 arg3);
void func_2D50F0(void *arg0, s32 arg1, s32 arg2, s32 arg3);
void func_2D53A0(void *arg0, s32 arg1, void *arg2);
s32 func_2D57D0(void *arg0, s32 arg1, s32 arg2, s32 arg3);
void func_2D6860(void *arg0, s32 arg1, void *arg2, s32 *arg3, s32 *arg4);
void func_2D6B20(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_2D6D10(void *arg0, s32 arg1);
void func_2D7040(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5);
void func_2D70A0(void *arg0, s32 arg1, s32 arg2);
void func_2D7120(void *arg0, s32 arg1, s32 arg2, s32 arg3);
void func_2D73C0(void *arg0, s32 arg1, s32 *arg2, s32 *arg3);
extern f32 D_003DF744 __attribute__((section(".sdata")));

void func_00464530(void *arg0, s32 arg1) {
    void *win;
    s32 count1;
    s32 count2;
    s32 other1;
    s32 other2;
    s32 half;

    win = func_2D34C0();
    if (win == 0) {
        return;
    }
    func_2D73C0(win, 0x2734, &count1, &count2);
    func_2D6860(win, 0x2737, arg0, &other1, &other2);
    func_2D6D10(win, 0x17A3);
    if (arg1 != 0) {
        func_2D7120(win, 0x17A3, count1 + 0x22, other2 - 2);
    } else {
        func_2D7040(win, 0x17A3, count1 + 0x22, other2 - 2, 0, D_003DF744);
    }
    func_2D53A0(win, 0x2737, arg0);
    func_2D7120(win, 0x1794, count1 + 0x40, other2 - 1);
    func_2D6B20(win, 0x1794, 0x1795, 0, 0);
    func_2D50F0(win, 0x1794, 0x82, 0);
    half = func_2D57D0(win, 0x2736, 0, 0);
    func_2D70A0(win, 0x2736, 0x66 - (half >> 1));
    func_2D38E0(win, 0x2738, 0, -1);
}
