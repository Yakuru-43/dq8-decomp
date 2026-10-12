// range: 0x217080 0x217090
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_0016DF60();

int func_00217080(void * arg0, void * arg1) {
    return func_0016DF60(arg0, *(s32 *)((char *)arg0 + 0x44BC));
}
