// range: 0x2C0330 0x2C0370
#include "common.h"

void func_0018DCB0(void *, s32, s32);
void *func_002C0180(s32, s32);

void func_002C0330(s32 arg0, s32 arg1) {
    void *temp_v0;

    temp_v0 = func_002C0180(arg0, 1);
    if (temp_v0 != 0) {
        func_0018DCB0(temp_v0, arg1, 0xABE);
    }
}
