// range: 0x14E540 0x14E550
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_0014E570();

int func_0014E540(void * arg0, void * arg1, void * arg2) {
    return func_0014E570(arg0, arg1, 1);
}
