// range: 0x167AA0 0x167AB0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern s32 D_003E0384;
extern int func_00222FC0();

int func_00167AA0(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00222FC0(D_003E0384, arg0, arg2, arg3);
}
