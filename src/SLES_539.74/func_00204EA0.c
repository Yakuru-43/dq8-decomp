// range: 0x204EA0 0x204EB0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00204EB0();

int func_00204EA0(void * arg0, void * arg1, void * arg2) {
    return func_00204EB0(arg0, arg1, (void *)0);
}
