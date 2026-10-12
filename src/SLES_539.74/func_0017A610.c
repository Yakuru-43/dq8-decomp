// range: 0x17A610 0x17A620
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern s32 D_003E04A0;
extern int func_0017A510();

int func_0017A610(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_0017A510(D_003E04A0, 24576, arg0, arg3);
}
