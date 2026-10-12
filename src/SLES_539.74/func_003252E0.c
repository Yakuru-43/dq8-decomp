// range: 0x3252E0 0x3252F0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_003252F0();

int func_003252E0(void * arg0, void * arg1) {
    return func_003252F0(arg0, 4);
}
