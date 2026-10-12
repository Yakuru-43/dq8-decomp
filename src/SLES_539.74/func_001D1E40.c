// range: 0x1D1E40 0x1D1E50
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_0010ADF8();

int func_001D1E40(void * arg0) {
    return func_0010ADF8((char *)arg0 + 0x30);
}
