// range: 0x152040 0x152050
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00153080();

int func_00152040(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00153080(arg1, *(s32 *) ((char *) (arg0) + 0x104), arg2, arg3);
}
