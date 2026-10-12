// range: 0x324CA0 0x324CB0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00324DB0();

int func_00324CA0(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00324DB0(39, 0, arg0, arg3);
}
