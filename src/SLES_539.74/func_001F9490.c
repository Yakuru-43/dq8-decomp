// range: 0x1F9490 0x1F94A0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_001FB120();

int func_001F9490(void * arg0, void * arg1) {
    return func_001FB120(arg0, (void *)0);
}
