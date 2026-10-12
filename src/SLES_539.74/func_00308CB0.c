// range: 0x308CB0 0x308CC0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00131188();

int func_00308CB0(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00131188(arg0, 0, 1408, arg3);
}
