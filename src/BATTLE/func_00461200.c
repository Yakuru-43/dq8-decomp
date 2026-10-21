// range: 0x461200 0x461210
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_1E73E0();

int func_00461200(void * arg0) {
    return func_1E73E0((char *)arg0 + 0x1F0);
}
