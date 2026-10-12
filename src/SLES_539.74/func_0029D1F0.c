// range: 0x29D1F0 0x29D200
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00131188();

int func_0029D1F0(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00131188(arg0, 0, 256, arg3);
}
