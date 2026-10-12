// range: 0x288A80 0x288A90
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_001E7870();

int func_00288A80(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_001E7870((char *) (arg0) + 0x1F0, -1, arg2, arg3);
}
