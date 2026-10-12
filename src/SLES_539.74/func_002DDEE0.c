// range: 0x2DDEE0 0x2DDEF0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_002DE570();

int func_002DDEE0(void *arg0, void *arg1, void *arg2, void *arg3) {
    *(s32 *) ((char *) (arg0) + 0x88) = 0;
    *(s32 *) ((char *) (arg0) + 0x90) = 0;
    *(s32 *) ((char *) (arg0) + 0x8C) = 0;
    return func_002DE570(arg0, arg1, arg2, arg3);
}
