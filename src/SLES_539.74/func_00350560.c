// range: 0x00350560 0x003505F0
#include "common.h"

s32 func_0012D4C0(s32);
void func_003505F0(char *, void *);
extern s32 D_003E137C;

void func_00350560(s32 arg0, s32 arg1, char *arg2) {
    s32 idx[4];
    s32 i;

    idx[0] = func_0012D4C0(arg0);
    idx[1] = func_0012D4C0(arg0 + arg1);
    for (i = 0; i < 2; i++) {
        func_003505F0(arg2 + i * 64, (char *)D_003E137C + idx[i] * 8);
    }
}
