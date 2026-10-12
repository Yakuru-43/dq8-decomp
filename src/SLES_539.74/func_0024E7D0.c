// range: 0x24E7D0 0x24E7E0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_002526F0();

int func_0024E7D0(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_002526F0(*(s32 *) ((char *) (arg0) + 0x0), 31, arg2, arg3);
}
