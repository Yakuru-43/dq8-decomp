// range: 0x3811A0 0x3811B0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern s32 D_003E0868;
extern int func_002CE6D0();

int func_003811A0(void * arg0) {
    return func_002CE6D0(D_003E0868);
}
