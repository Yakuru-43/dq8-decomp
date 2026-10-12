// range: 0x30C3B0 0x30C3C0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00356910();

int func_0030C3B0(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00356910(arg0, *(s32 *) ((char *) (*(s32 *) ((char *) (arg1) + 0x158)) + 0x0), arg2, arg3);
}
