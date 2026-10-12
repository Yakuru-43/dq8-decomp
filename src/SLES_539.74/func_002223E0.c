// range: 0x2223E0 0x2223F0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_002223D0();

int func_002223E0(void * arg0, void * arg1) {
    return func_002223D0(arg0, (void *)0);
}
