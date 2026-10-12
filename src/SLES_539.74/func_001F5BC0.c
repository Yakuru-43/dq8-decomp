// range: 0x1F5BC0 0x1F5BD0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_001F8E50();

int func_001F5BC0(void * arg0, void * arg1) {
    return func_001F8E50(arg0, 1);
}
