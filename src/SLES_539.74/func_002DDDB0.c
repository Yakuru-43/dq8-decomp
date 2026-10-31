// range: 0x2DDDB0 0x2DDE50
#include "common.h"

void func_0013E410(char *, s32);
void func_0013E2F0(char *, s32);

void func_002DDDB0(s32 arg0, char *arg1) {
    u32 flags = arg0 & 0xFFFF;

    if (flags & 2) {
        func_0013E410(arg1, 2);
    } else {
        if (flags & 4) {
            func_0013E410(arg1, 3);
        } else {
            func_0013E410(arg1, 1);
        }
    }

    if (flags & 8) {
        func_0013E2F0(arg1, 1);
    } else {
        func_0013E2F0(arg1, 0);
    }
}
