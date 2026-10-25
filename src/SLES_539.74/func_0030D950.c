// range: 0x30D950 0x30D9A0
#include "common.h"

extern s32 func_00356710(void *, void *);
extern void *func_00356920(void *, s32);

void func_0030D950(char *arg0) {
    if (func_00356710(arg0 + 0x160, arg0 + 0x168) != 0) {
        func_00356920(arg0 + 0x170, 1);
    } else {
        func_00356920(arg0 + 0x170, 0);
    }
}
