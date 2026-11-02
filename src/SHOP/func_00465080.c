// range: 0x465080 0x465190
#include "common.h"

void *func_2D34C0(void);
void func_2D6B20(void *, s32, s32, s32, s32);
void func_2D6A80(void *, s32, s32, s32, s32, s32, f32);

void func_00465080(s32 arg0, s32 arg1) {
    void *panel;
    s32 idx;
    s32 flag;
    s32 w;
    s32 w2;

    idx = arg0;
    flag = arg1;
    panel = func_2D34C0();
    if (flag != 0) {
        func_2D6B20(panel, 0x177B, 0x17A3, -0x1A, ((idx * 33) << 1) + 4);
    } else {
        func_2D6A80(panel, 0x177B, 0x17A3, -0x1A, ((idx * 33) << 1) + 4, 0, 0.5f);
    }
    w = idx * 66;
    w2 = w - 2;
    func_2D6B20(panel, 0x177E, 0x1781, -0xA, w2);
    func_2D6B20(panel, 0x177B, 0x1778, -0xC, w - 20);
    func_2D6B20(panel, 0x177B, 0x1783, 0, w2);
    func_2D6B20(panel, 0x177B, 0x1785, 0xC0, w - 25);
}
