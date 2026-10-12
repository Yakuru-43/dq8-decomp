// range: 0x30BC90 0x30BCA0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00356910();

int func_0030BC90(void * arg0, void * arg1) {
    return func_00356910(arg0, (void *)0);
}
