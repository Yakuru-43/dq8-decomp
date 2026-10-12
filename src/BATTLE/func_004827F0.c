// range: 0x4827F0 0x482800
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_281CB0();

int func_004827F0(void * arg0, void * arg1, void * arg2) {
    return func_281CB0(arg0, arg1, (void *)0);
}
