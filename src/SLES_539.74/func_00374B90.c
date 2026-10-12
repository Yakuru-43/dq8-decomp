// range: 0x374B90 0x374BB0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern s32 D_003E0874;
extern int func_003123C0();

int func_00374B90(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_003123C0(D_003E0874, arg0, arg1, arg3);
}
