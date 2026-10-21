// range: 0x46B000 0x46B020
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_37AB80();

int func_0046B000(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_37AB80(3, *(s16 *) ((char *) (*(s32 *) ((char *) (arg0) + 0x18)) + 0x12), 1, arg3);
}
