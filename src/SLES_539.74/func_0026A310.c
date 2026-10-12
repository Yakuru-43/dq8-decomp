// range: 0x26A310 0x26A330
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_0013B6D0();

int func_0026A310(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_0013B6D0(arg1, (char *) (arg0) + 0x30, (char *) (arg0) + 0x80, arg3);
}
