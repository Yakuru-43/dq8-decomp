// range: 0x15F230 0x15F240
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern s32 D_003E0298;
extern int func_00141CE0();

int func_0015F230(void * arg0) {
    return func_00141CE0(D_003E0298);
}
