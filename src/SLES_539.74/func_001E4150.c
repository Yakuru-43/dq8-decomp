// range: 0x1E4150 0x1E4170
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00131188();

int func_001E4150(void *arg0, void *arg1, void *arg2, void *arg3) {
    *(s32 *) ((char *) (arg0) + 0x0) = 0;
    *(s32 *) ((char *) (arg0) + 0x4) = 0;
    return func_00131188((char *) (arg0) + 0x10, 0, 32, arg3);
}
