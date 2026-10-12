// range: 0x308760 0x308770
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00131188();

int func_00308760(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00131188(arg0, 0, 48, arg3);
}
