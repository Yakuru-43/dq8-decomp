// range: 0x16A150 0x16A160
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_001007A0();

int func_0016A150(void * arg0, void * arg1) {
    return func_001007A0(arg1, arg1);
}
