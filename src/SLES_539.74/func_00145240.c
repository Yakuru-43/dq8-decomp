// range: 0x145240 0x145250
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00157FB0();

int func_00145240(void * arg0) {
    return func_00157FB0(*(s32 *)((char *)arg0 + 0x270));
}
