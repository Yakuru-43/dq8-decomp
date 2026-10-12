// range: 0x169B50 0x169B60
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_001007A0();

int func_00169B50(void * arg0, void * arg1) {
    return func_001007A0(arg1, arg1);
}
