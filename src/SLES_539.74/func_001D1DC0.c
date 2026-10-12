// range: 0x1D1DC0 0x1D1DD0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_0010ADF8();

int func_001D1DC0(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_0010ADF8(arg1, (char *) (arg0) + 0x30, arg2, arg3);
}
