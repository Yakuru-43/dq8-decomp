// range: 0x324CD0 0x324CE0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00324DB0();

int func_00324CD0(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00324DB0(44, 63, arg0, arg3);
}
