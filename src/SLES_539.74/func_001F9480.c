// range: 0x1F9480 0x1F9490
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_001FB120();

int func_001F9480(void * arg0, void * arg1) {
    return func_001FB120(arg0, 1);
}
