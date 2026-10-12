// range: 0x2252C0 0x2252D0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_001E7360();

int func_002252C0(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_001E7360((char *) (arg0) + 0x1F0, -1, arg2, arg3);
}
