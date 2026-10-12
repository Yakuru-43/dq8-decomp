// range: 0x324D10 0x324D20
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00324DB0();

int func_00324D10(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00324DB0(46, 0, arg0, arg3);
}
