// range: 0x324CB0 0x324CC0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00324DB0();

int func_00324CB0(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00324DB0(68, 0, arg0, arg3);
}
