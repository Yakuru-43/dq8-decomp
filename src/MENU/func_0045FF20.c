// range: 0x45FF20 0x460090
#include "common.h"

extern void *func_2D34C0(void);
void func_2D4EB0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_2D73C0(void *arg0, s32 arg1, s32 *arg2, s32 *arg3);
void func_2D7120(void *arg0, s32 arg1, s32 arg2, s32 arg3);
void func_2D38E0(void *arg0, s32 arg1, s32 arg2, s32 arg3);
extern void *func_37AD10(void);
void func_2D48B0(void *arg0, s32 arg1, f32 arg2);
void func_2D6A80(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4,
                 s32 arg5, f32 arg6);

void func_0045FF20(void *arg0, s32 arg1, s32 arg2) {
    void *win;
    s32 count1;
    s32 count2;
    void *owner;

    win = func_2D34C0();
    if (arg2 < 0) {
        func_2D38E0(win, 0x4AA, 0, -1);
        return;
    }
    func_2D4EB0(win, 0x4AA, 0, arg2, 1);
    func_2D73C0(win, 0x474, &count1, &count2);
    func_2D7120(win, 0x4AA, count1 + ((arg1 % 4) * 48 + 2),
                count2 + ((arg1 / 4) * 48 + 30));
    func_2D38E0(win, 0x4AA, 1, -1);
    owner = func_37AD10();
    if (arg0 == owner) {
        func_2D48B0(win, 0x4AA, 0.0f);
    } else {
        func_2D6A80(win, (char *)owner + 0x2B70, 0x4AA, 0x14, 0xC, 0, 0.5f);
        func_2D48B0(win, 0x4AA, 1.0f);
    }
}
