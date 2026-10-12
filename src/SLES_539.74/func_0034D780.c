// range: 0x34D780 0x34D790
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00131188();

int func_0034D780(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00131188(arg0, 0, 128, arg3);
}
