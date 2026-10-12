// range: 0x24E6C0 0x24E6E0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00252400();

int func_0024E6C0(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00252400(3, 128, *(s32 *) ((char *) (arg0) + 0x0), *(s32 *) ((char *) (arg0) + 0x4));
}
