// range: 0x24B840 0x24B860
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00130FD0();

int func_0024B840(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00130FD0(arg1, (char *) (arg0) + 0x40, 28, arg3);
}
