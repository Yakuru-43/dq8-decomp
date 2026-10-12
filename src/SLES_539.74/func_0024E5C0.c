// range: 0x24E5C0 0x24E5D0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00252648();

int func_0024E5C0(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00252648(3, *(s32 *) ((char *) (arg0) + 0x0), arg2, arg3);
}
