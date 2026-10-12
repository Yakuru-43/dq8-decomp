// range: 0x205040 0x205050
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00205050();

int func_00205040(void * arg0, void * arg1, void * arg2) {
    return func_00205050(arg0, arg1, (void *)0);
}
