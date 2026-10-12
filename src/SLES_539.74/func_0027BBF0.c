// range: 0x27BBF0 0x27BC00
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern s32 D_003E0D94;
extern int func_00222FC0();

int func_0027BBF0(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00222FC0(D_003E0D94, arg0, arg2, arg3);
}
