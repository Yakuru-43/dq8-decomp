// range: 0x324D80 0x324D90
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00324DB0();

int func_00324D80(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00324DB0(22, 0, arg0, arg3);
}
