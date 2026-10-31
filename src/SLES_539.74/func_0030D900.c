// range: 0x30D900 0x30D950
#include "common.h"

extern s32 func_003565B0(void *, void *);
extern void *func_00356920(void *, s32);

void func_0030D900(char *arg0) {
    if (func_003565B0(arg0 + 0x160, arg0 + 0x168) != 0) {
        func_00356920(arg0 + 0x170, 1);
    } else {
        func_00356920(arg0 + 0x170, 0);
    }
}
