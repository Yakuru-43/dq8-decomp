// range: 0x209BE0 0x209BF0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00209BF0();

int func_00209BE0(void * arg0, void * arg1, void * arg2, void * arg3) {
    return func_00209BF0(arg0, arg1, arg2, 1);
}
