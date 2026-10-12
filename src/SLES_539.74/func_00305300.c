// range: 0x305300 0x305310
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00131188();

int func_00305300(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00131188(arg0, 0, 16784, arg3);
}
