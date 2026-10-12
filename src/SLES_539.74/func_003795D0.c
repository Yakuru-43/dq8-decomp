// range: 0x3795D0 0x3795E0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00379510();

int func_003795D0(void * arg0, void * arg1, void * arg2) {
    return func_00379510(arg0, arg1, (void *)0);
}
