// range: 0x36B070 0x36B080
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00131188();

int func_0036B070(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00131188(arg0, 0, 1348, arg3);
}
