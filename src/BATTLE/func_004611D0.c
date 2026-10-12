// range: 0x4611D0 0x4611E0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_1E7360();

int func_004611D0(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_1E7360((char *) (arg0) + 0x1F0, -1, arg2, arg3);
}
