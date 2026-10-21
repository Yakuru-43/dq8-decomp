// range: 0x462310 0x462320
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_2E19B0();

int func_00462310(void * arg0, void * arg1) {
    return func_2E19B0(arg0, (u32)arg1 & 0xFF);
}
