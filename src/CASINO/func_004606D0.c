// range: 0x4606D0 0x4606E0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_10ADF8();

int func_004606D0(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_10ADF8(arg1, (char *) (arg0) + 0x40, arg2, arg3);
}
