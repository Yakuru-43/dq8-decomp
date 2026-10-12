// range: 0x1735C0 0x1735D0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_001735D0();

int func_001735C0(void * arg0, void * arg1, void * arg2, void * arg3) {
    return func_001735D0(arg0, arg1, arg2, 1);
}
