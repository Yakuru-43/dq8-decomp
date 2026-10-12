// range: 0x1D6CF0 0x1D6D00
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern s32 D_003E071C;
extern int func_00339A40();

int func_001D6CF0(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00339A40((char *) (D_003E071C) + 0x6B34, arg0, arg2, arg3);
}
