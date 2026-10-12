// range: 0x288AA0 0x288AB0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_001E7550();

int func_00288AA0(void * arg0) {
    return func_001E7550((char *)arg0 + 0x1F0);
}
