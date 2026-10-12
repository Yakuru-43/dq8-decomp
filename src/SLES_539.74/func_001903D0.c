// range: 0x1903D0 0x1903E0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_0016AF30();

int func_001903D0(void * arg0, void * arg1) {
    return func_0016AF30(arg0, *(s32 *)((char *)arg0 + 0x44B4));
}
