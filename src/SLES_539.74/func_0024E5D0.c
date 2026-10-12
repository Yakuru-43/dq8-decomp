// range: 0x24E5D0 0x24E5E0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00252BC0();

int func_0024E5D0(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00252BC0(0, *(s32 *) ((char *) (arg0) + 0x0), arg2, arg3);
}
