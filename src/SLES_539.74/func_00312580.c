// range: 0x312580 0x3125A0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern s32 D_003E0868;
extern int func_00220080();

int func_00312580(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00220080(D_003E0868, arg0, arg1, -1);
}
