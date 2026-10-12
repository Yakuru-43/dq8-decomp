// range: 0x18D730 0x18D740
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_0016C320();

int func_0018D730(void * arg0) {
    *(volatile s32 *)((char *)arg0 + 0x38) = 0;
    return func_0016C320(arg0);
}
