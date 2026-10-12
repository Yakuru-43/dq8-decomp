// range: 0x324C70 0x324C80
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00324DB0();

int func_00324C70(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00324DB0(67, 0, arg0, arg3);
}
