// range: 0x2224D0 0x2224E0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_002E19B0();

int func_002224D0(void * arg0, void * arg1) {
    return func_002E19B0(arg0, (u32)arg1 & 0xFF);
}
