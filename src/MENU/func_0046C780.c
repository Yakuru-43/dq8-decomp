// range: 0x46C780 0x46C790
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_37AB80();

int func_0046C780(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_37AB80(2, 0, 1, arg3);
}
