// range: 0x24E5E0 0x24E5F0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00252918();

int func_0024E5E0(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00252918(0, *(s32 *) ((char *) (arg0) + 0x0), arg2, arg3);
}
