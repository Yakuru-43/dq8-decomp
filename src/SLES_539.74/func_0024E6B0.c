// range: 0x24E6B0 0x24E6C0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_002529B8();

int func_0024E6B0(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_002529B8(*(s32 *) ((char *) (arg0) + 0x0), 3, 0, arg3);
}
