// range: 0x324CC0 0x324CD0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00324DB0();

int func_00324CC0(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00324DB0(24, 65, arg0, arg3);
}
