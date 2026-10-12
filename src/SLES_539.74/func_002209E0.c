// range: 0x2209E0 0x2209F0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00214C00();

int func_002209E0(void *arg0, void *arg1, void *arg2, void *arg3) {
    *(s32 *) ((char *) (arg0) + 0x11C4) = -1;
    return func_00214C00(arg0, arg1, arg2, arg3);
}
