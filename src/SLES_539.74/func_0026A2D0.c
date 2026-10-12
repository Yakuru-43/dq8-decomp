// range: 0x26A2D0 0x26A2F0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_0013B7B0();

int func_0026A2D0(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_0013B7B0(arg1, (char *) (arg0) + 0x50, (char *) (arg0) + 0xA0, arg3);
}
