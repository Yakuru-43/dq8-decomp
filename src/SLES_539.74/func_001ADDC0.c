// range: 0x1ADDC0 0x1ADDD0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern s32 D_003DFCCC;
extern int func_0036F0F0();

int func_001ADDC0(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_0036F0F0(D_003DFCCC, arg0, arg2, arg3);
}
