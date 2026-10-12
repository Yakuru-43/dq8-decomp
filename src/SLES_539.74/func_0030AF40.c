// range: 0x30AF40 0x30AF50
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern s32 D_003E116C;
extern int func_00356910();

int func_0030AF40(void * arg0, void * arg1) {
    return func_00356910(arg0, D_003E116C);
}
