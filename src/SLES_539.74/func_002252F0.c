// range: 0x2252F0 0x225300
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_0014DF80();

int func_002252F0(void * arg0) {
    return func_0014DF80(*(s32 *)((char *)arg0 + 0x58));
}
