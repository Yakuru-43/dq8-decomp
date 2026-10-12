// range: 0x2C0730 0x2C0740
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern s32 D_003E0FFC;
extern int func_002C0740();

int func_002C0730(void * arg0, void * arg1, void * arg2) {
    return func_002C0740(arg0, arg1, D_003E0FFC);
}
