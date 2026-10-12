// range: 0x190670 0x190680
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_0016BEF0();

int func_00190670(void * arg0, void * arg1) {
    return func_0016BEF0(arg0, *(s32 *)((char *)arg0 + 0x508));
}
