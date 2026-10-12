// range: 0x276EB0 0x276EC0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_0013B6D0();

int func_00276EB0(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_0013B6D0(arg1, (char *) (arg0) + 0x40, arg2, arg3);
}
