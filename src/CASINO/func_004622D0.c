// range: 0x4622D0 0x4622E0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_2E19B0();

int func_004622D0(void * arg0, void * arg1) {
    return func_2E19B0(arg0, (u32)arg1 & 0xFF);
}
