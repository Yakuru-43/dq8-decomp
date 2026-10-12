// range: 0x465C80 0x465C90
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_37A850();

int func_00465C80(void * arg0, void * arg1, void * arg2) {
    return func_37A850(arg0, arg1, 4);
}
