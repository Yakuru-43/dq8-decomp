// range: 0x2204B0 0x2204C0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00131188();

int func_002204B0(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00131188(arg0, 0, 140, arg3);
}
