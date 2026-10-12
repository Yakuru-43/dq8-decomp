// range: 0x324D90 0x324DA0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00324DB0();

int func_00324D90(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00324DB0(9, 0, arg0, arg3);
}
