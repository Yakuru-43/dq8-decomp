// range: 0x24E700 0x24E720
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_002524C0();

int func_0024E700(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_002524C0(*(s32 *) ((char *) (arg0) + 0x4), *(s32 *) ((char *) (arg0) + 0x8), *(s32 *) ((char *) (arg0) + 0xC), *(s32 *) ((char *) (arg0) + 0x10));
}
