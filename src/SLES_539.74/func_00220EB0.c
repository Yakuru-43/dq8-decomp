// range: 0x220EB0 0x220EF0
#include "common.h"

extern void func_00220EF0(void *arg0, s32 arg1);

void func_00220EB0(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s8 *, 0x1639) = -1;
    M2C_FIELD(arg0, s8 *, 0x1F36) = arg1;
    if (0 <= arg2) {
        func_00220EF0(arg0, arg2);
    }
}
