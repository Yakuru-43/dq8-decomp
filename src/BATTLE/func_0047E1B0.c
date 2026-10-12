// range: 0x47E1B0 0x47E1C0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00472130();

int func_0047E1B0(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00472130(arg0, *(s32 *) ((char *) (arg1) + 0x4), *(s32 *) ((char *) (arg2) + 0x50), arg3);
}
