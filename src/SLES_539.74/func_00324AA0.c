// range: 0x324AA0 0x324AB0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00324AB0();

int func_00324AA0(void * arg0, void * arg1) {
    return func_00324AB0(arg0, (void *)0);
}
