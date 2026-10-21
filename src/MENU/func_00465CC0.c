// range: 0x465CC0 0x465CD0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_37A850();

int func_00465CC0(void * arg0, void * arg1, void * arg2) {
    return func_37A850(arg0, arg1, 4);
}
