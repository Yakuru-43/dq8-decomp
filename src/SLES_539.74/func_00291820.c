// range: 0x291820 0x291830
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00291830();

int func_00291820(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00291830(arg0, 1, 2, arg3);
}
