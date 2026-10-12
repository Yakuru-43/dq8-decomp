// range: 0x1FFC20 0x1FFC30
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern s32 D_003E086C;
extern int func_00223150();

int func_001FFC20(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00223150(D_003E086C, arg0, arg2, arg3);
}
