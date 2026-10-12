// range: 0x1D1E30 0x1D1E40
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_0010ADF8();

int func_001D1E30(void * arg0) {
    return func_0010ADF8((char *)arg0 + 0x40);
}
