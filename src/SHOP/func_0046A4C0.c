// range: 0x46A4C0 0x46A4D0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00469F40();

int func_0046A4C0(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00469F40(3, -1, arg2, arg3);
}
