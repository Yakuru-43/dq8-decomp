// range: 0x1FFC30 0x1FFC40
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern s32 D_003E0860;
extern int func_00222FC0();

int func_001FFC30(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00222FC0(D_003E0860, arg0, arg2, arg3);
}
