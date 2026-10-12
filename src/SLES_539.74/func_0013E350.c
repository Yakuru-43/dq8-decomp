// range: 0x13E350 0x13E360
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_001578D0();

int func_0013E350(void * arg0) {
    return func_001578D0((char *)arg0 + 0x10);
}
