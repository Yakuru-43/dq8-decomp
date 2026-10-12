// range: 0x324D30 0x324D40
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00324DB0();

int func_00324D30(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00324DB0(18, 0, arg0, arg3);
}
