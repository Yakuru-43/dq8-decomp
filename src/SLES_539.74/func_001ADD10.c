// range: 0x1ADD10 0x1ADD20
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern s32 D_003E06B4;
extern int func_00223070();

int func_001ADD10(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00223070(D_003E06B4, arg0, arg2, arg3);
}
