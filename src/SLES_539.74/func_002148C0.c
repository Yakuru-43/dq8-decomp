// range: 0x2148C0 0x2148E0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern s32 D_003E08EC;
extern u8 D_003E08F0;
extern int func_001FF910();

int func_002148C0(void *arg0, void *arg1, void *arg2, void *arg3) {
    D_003E08F0 = 1;
    return func_001FF910(D_003E08EC, 6, arg2, arg3);
}
