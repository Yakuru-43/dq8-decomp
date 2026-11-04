// CLASS structural score=2 (2 words differ, 556 vs 556 bytes)  -- best attempt
// range: 0x22B120 0x22B350
#include "common.h"

void func_0013E2B0(s32, s32);
void func_0013E2D0(s32, s32);
void func_0013E2F0(s32, s32);
void func_0013E320(s32, s32);
void func_0013E360(s32, s32);
void func_0013E390(s32, s32);
void func_0013E3E0(s32, s32, s32);
void func_0013E3F0(s32, s32);
void func_0013E410(s32, s32);
void func_0013E420(s32, s32);
void func_0013FA20(void);

void func_0022B120(s32 arg0, s32 arg1) {
    if (arg0 == 0) {
        return;
    }
    func_0013FA20();
    switch (arg1) {
    case 0:
    case 3:
        func_0013E420(arg0, 1);
        func_0013E2F0(arg0, 0);
        if (arg1 == 3) {
            func_0013E410(arg0, 2);
            func_0013E2F0(arg0, 1);
        } else {
            func_0013E410(arg0, 1);
        }
        func_0013E3F0(arg0, 1);
        func_0013E3E0(arg0, 1, 0);
        func_0013E390(arg0, 0);
        func_0013E360(arg0, 1);
        func_0013E2D0(arg0, 0);
        func_0013E320(arg0, 1);
        func_0013E2B0(arg0, 0);
        return;
    case 1:
    case 2:
        func_0013E420(arg0, 1);
        func_0013E2F0(arg0, 0);
        func_0013E410(arg0, 1);
        func_0013E3F0(arg0, 1);
        func_0013E3E0(arg0, 1, 0);
        func_0013E320(arg0, 0);
        func_0013E390(arg0, 1);
        if (arg1 == 2) {
            func_0013E390(arg0, 0);
            func_0013E2B0(arg0, 1);
        }
        func_0013E360(arg0, 1);
        func_0013E2D0(arg0, 1);
        return;
    case 4:
        func_0013E3F0(arg0, 0);
        func_0013E3E0(arg0, 1, 0);
        func_0013E420(arg0, 0);
        func_0013E410(arg0, 0);
        func_0013E390(arg0, 0);
        func_0013E360(arg0, 1);
        func_0013E2D0(arg0, 0);
        func_0013E320(arg0, 1);
        func_0013E2F0(arg0, 1);
        return;
    default:
        return;
    }
}
