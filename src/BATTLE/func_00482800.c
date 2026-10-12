// range: 0x482800 0x482810
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_281CB0();

int func_00482800(void * arg0, void * arg1, void * arg2) {
    return func_281CB0(arg0, arg1, 1);
}
