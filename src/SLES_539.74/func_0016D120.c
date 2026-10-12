// range: 0x16D120 0x16D130
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_0016D130();

int func_0016D120(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_0016D130(arg1, arg2, arg3, arg3);
}
