// range: 0x464200 0x464210
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_16AF30();

int func_00464200(void * arg0, void * arg1) {
    return func_16AF30(arg0, *(s32 *)((char *)arg0 + 0x44B4));
}
