// range: 0x4641C0 0x4641D0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_16AF30();

int func_004641C0(void * arg0, void * arg1) {
    return func_16AF30(arg0, *(s32 *)((char *)arg0 + 0x44B4));
}
