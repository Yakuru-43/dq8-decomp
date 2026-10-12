// range: 0x24E610 0x24E620
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00252A70();

int func_0024E610(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00252A70(*(s32 *) ((char *) (arg0) + 0x0), *(s32 *) ((char *) (arg0) + 0x4), arg2, arg3);
}
