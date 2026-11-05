// range: 0x4696D0 0x4697B0
#include "common.h"

extern char *func_0046DDF0(void);
void func_2D5440(void *, s32, void *);
void func_37EDD0(void *, s32, s32, s32 *, s32 *);
void func_2D4FC0(void *, s32, s32, s32);
void func_2D7120(void *arg0, s32 arg1, s32 arg2, s32 arg3);
void func_2D70A0(void *arg0, s32 arg1, s32 arg2);
void func_2D38E0(void *arg0, s32 arg1, s32 arg2, s32 arg3);
void func_004697B0(s32 arg0, s32 arg1);

void func_004696D0(void *arg0) {
    char *win;
    s32 local_3C;
    s32 local_38;

    win = func_0046DDF0();
    func_2D5440(win, 0x2737, arg0);
    local_3C = -1;
    local_38 = -1;
    func_37EDD0(win, 0x2734, 0x2737, &local_3C, &local_38);
    func_2D4FC0(win, 0x2734, local_3C + 0x1C, local_38);
    func_2D7120(win, 0x2737, 0x12, -1);
    func_2D7120(win, 0x2733, 0x5C, 0x82);
    func_2D70A0(win, 0x2738, 8);
    func_2D38E0(win, 0x2733, 1, -1);
    func_004697B0(0, 1);
}
