// range: 0x2DECC0 0x2DECD0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_002DECD0();

int func_002DECC0(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_002DECD0(arg0, arg0, *(s32 *) ((char *) (arg0) + 0x94), *(s32 *) ((char *) (arg0) + 0x98));
}
