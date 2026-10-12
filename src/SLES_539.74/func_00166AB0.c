// range: 0x166AB0 0x166AC0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_0010AC90();

int func_00166AB0(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_0010AC90(arg1, (char *) (arg0) + 0x10, arg2, arg3);
}
