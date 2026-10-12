// range: 0x469880 0x469890
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00469F40();

int func_00469880(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00469F40(-1, arg0, arg2, arg3);
}
