// range: 0x3252D0 0x3252E0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_003252F0();

int func_003252D0(void * arg0, void * arg1) {
    return func_003252F0(arg0, 3);
}
