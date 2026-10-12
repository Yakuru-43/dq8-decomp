// range: 0x15F240 0x15F250
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern s32 D_003E0298;
extern int func_00141D10();

int func_0015F240(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00141D10(D_003E0298, arg0, arg2, arg3);
}
