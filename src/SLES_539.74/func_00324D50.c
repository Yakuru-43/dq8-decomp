// range: 0x324D50 0x324D60
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00324DB0();

int func_00324D50(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00324DB0(20, 0, arg0, arg3);
}
