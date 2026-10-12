// range: 0x2223C0 0x2223D0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_002223D0();

int func_002223C0(void * arg0, void * arg1) {
    return func_002223D0(arg0, (void *)0);
}
