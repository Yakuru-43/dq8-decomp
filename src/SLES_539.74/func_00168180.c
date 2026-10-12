// range: 0x168180 0x168190
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00131188();

int func_00168180(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00131188(arg0, 0, 88, arg3);
}
