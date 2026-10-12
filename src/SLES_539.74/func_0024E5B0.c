// range: 0x24E5B0 0x24E5C0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00252918();

int func_0024E5B0(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00252918(5, *(s32 *) ((char *) (arg0) + 0x0), arg2, arg3);
}
