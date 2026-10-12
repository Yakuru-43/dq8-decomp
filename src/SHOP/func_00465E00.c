// range: 0x465E00 0x465E10
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_281CB0();

int func_00465E00(void * arg0, void * arg1, void * arg2) {
    return func_281CB0(arg0, arg1, (void *)0);
}
