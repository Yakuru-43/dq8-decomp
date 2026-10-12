// range: 0x312550 0x312560
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern s32 D_003E0868;
extern int func_002CF170();

int func_00312550(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_002CF170(D_003E0868, arg0, 1, arg3);
}
