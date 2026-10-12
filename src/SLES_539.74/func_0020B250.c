// range: 0x20B250 0x20B260
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_003062B0();

int func_0020B250(void * arg0, void * arg1) {
    return func_003062B0(arg1, arg1);
}
