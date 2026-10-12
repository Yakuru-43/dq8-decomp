// range: 0x297090 0x2970A0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00201760();

int func_00297090(void * arg0, void * arg1) {
    return func_00201760(arg0, (void *)0);
}
