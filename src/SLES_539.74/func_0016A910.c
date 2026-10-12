// range: 0x16A910 0x16A920
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00281CB0();

int func_0016A910(void * arg0, void * arg1, void * arg2) {
    return func_00281CB0(arg0, arg1, 1);
}
