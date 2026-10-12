// range: 0x2D4B40 0x2D4B50
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_002D4B50();

int func_002D4B40(void * arg0, void * arg1, void * arg2) {
    return func_002D4B50(arg0, arg1, (void *)0);
}
