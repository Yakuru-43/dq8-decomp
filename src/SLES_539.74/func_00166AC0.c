// range: 0x166AC0 0x166AE0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_0013B620();

int func_00166AC0(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_0013B620((char *) (arg0) + 0x80, arg3, arg2, arg1);
}
