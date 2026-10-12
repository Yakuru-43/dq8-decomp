// range: 0x26A370 0x26A380
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_0013B7B0();

int func_0026A370(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_0013B7B0((char *) (arg0) + 0x10, (char *) (arg0) + 0x10, arg1, arg3);
}
