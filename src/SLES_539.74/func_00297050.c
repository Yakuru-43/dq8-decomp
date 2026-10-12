// range: 0x297050 0x297060
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00201740();

int func_00297050(void * arg0, void * arg1) {
    return func_00201740(arg0, (void *)0);
}
