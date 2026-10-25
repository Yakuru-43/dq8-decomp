// range: 0x2179D0 0x2179E0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern void func_00217820(void *arg0, void *arg1, void *arg2, void *arg3,
                          void *arg4);

void func_002179D0(void *arg0, void *arg1, void *arg2) {
    func_00217820(arg0, arg1, arg1, arg1, arg2);
}
