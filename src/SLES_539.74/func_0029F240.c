// range: 0x29F240 0x29F280
#include "common.h"

void func_00286BE0(s32 arg0, s32 arg1);
void func_00286B30(s32 arg0, s32 arg1);

void func_0029F240(s32 arg0, s32 arg1, s32 arg2) {
    if (arg0 == 0) {
        return;
    }
    if (arg1 == 0) {
        return;
    }
    if (arg2 != 0) {
        func_00286BE0(arg0, arg1);
    } else {
        func_00286B30(arg0, arg1);
    }
}
