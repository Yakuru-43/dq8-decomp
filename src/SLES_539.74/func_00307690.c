// range: 0x307690 0x3076A0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern s32 D_003E1148;
extern int func_001745A0();

int func_00307690(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_001745A0(D_003E1148, arg0, 0, arg3);
}
