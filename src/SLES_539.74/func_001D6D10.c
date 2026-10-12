// range: 0x1D6D10 0x1D6D30
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern s32 D_003E071C;
extern int func_00339BA0();

int func_001D6D10(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00339BA0((char *) (D_003E071C) + 0x6B34, arg0, arg1, arg3);
}
