// range: 0x24E590 0x24E5A0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00252648();

int func_0024E590(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00252648(5, *(s32 *) ((char *) (arg0) + 0x0), arg2, arg3);
}
