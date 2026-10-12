// range: 0x1903E0 0x1903F0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_0016D5B0();

int func_001903E0(void * arg0, void * arg1) {
    return func_0016D5B0(arg0, *(s32 *)((char *)arg0 + 0x44B0));
}
