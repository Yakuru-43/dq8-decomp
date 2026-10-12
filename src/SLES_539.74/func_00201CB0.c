// range: 0x201CB0 0x201CC0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00131188();

int func_00201CB0(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00131188(arg0, 0, 4, arg3);
}
