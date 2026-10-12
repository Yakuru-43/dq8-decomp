// range: 0x350B70 0x350B80
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_003506B0();

int func_00350B70(void *arg0, void *arg1, void *arg2, void *arg3) {
    *(s32 *) ((char *) (arg0) + 0x18B0) = 0;
    return func_003506B0((char *) (arg0) + 0x18B4, arg1, arg2, arg3);
}
