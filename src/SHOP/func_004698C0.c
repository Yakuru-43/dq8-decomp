// range: 0x4698C0 0x4698D0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00469F40();

int func_004698C0(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00469F40(-1, arg0, arg2, arg3);
}
