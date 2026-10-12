// range: 0x24E740 0x24E760
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00252B10();

int func_0024E740(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00252B10(5, *(s32 *) ((char *) (arg0) + 0x0), *(s32 *) ((char *) (arg0) + 0x4), arg3);
}
