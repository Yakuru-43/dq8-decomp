// range: 0x461210 0x461220
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_1E7360();

int func_00461210(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_1E7360((char *) (arg0) + 0x1F0, -1, arg2, arg3);
}
