// range: 0x2252E0 0x2252F0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_0014E130();

int func_002252E0(void * arg0) {
    return func_0014E130(*(s32 *)((char *)arg0 + 0x58));
}
