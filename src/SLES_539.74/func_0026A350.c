// range: 0x26A350 0x26A370
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_0013B7B0();

int func_0026A350(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_0013B7B0(arg1, (char *) (arg0) + 0x10, (char *) (arg0) + 0x60, arg3);
}
