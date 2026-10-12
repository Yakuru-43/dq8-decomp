// range: 0x222EE0 0x222EF0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_001FFC10();

int func_00222EE0(void * arg0) {
    return func_001FFC10((char *)arg0 + 0x64);
}
