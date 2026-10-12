// range: 0x1E29F0 0x1E2A00
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_0014AFD0();

int func_001E29F0(void *arg0, void *arg1, void *arg2, void *arg3) {
    *(s32 *) ((char *) (arg0) + 0xF0) = 1;
    *(s32 *) ((char *) (arg0) + 0xF4) = 0;
    return func_0014AFD0(arg0, arg1, arg2, arg3);
}
