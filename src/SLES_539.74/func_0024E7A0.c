// range: 0x24E7A0 0x24E7B0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00252B10();

int func_0024E7A0(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00252B10(0, *(s32 *) ((char *) (arg0) + 0x0), arg2, arg3);
}
