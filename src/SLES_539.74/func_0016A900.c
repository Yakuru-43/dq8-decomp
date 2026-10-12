// range: 0x16A900 0x16A910
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00281CB0();

int func_0016A900(void * arg0, void * arg1, void * arg2) {
    return func_00281CB0(arg0, arg1, (void *)0);
}
