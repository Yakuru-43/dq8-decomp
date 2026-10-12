// range: 0x465E10 0x465E20
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_281CB0();

int func_00465E10(void * arg0, void * arg1, void * arg2) {
    return func_281CB0(arg0, arg1, 1);
}
