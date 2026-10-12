// range: 0x14E550 0x14E560
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_0014E640();

int func_0014E550(void * arg0, void * arg1, void * arg2) {
    return func_0014E640(arg0, arg1, 4);
}
