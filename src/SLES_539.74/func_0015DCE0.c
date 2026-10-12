// range: 0x15DCE0 0x15DCF0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern s32 D_003E0298;
extern int func_00144C60();

int func_0015DCE0(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00144C60(D_003E0298, arg0, arg2, arg3);
}
