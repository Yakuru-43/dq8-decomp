// range: 0x190AA0 0x190AB0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_0016DF20();

int func_00190AA0(void * arg0, void * arg1) {
    return func_0016DF20(arg0, *(s32 *)((char *)arg0 + 0x44BC));
}
