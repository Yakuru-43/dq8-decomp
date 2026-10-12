// range: 0x2D34D0 0x2D34F0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00375C70();

int func_002D34D0(void *arg0, void *arg1, void *arg2, void *arg3) {
    *(s32 *) ((char *) (arg0) + 0x1C) = 0;
    *(s32 *) ((char *) (arg0) + 0x4) = 0;
    *(s32 *) ((char *) (arg0) + 0x14) = 0;
    *(s32 *) ((char *) (arg0) + 0x18) = 0;
    *(s32 *) ((char *) (arg0) + 0x8) = 0;
    *(s32 *) ((char *) (arg0) + 0x20) = 0;
    return func_00375C70((char *) (arg0) + 0xC, arg1, arg2, arg3);
}
