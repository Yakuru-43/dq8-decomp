// range: 0x13E380 0x13E390
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00157990();

int func_0013E380(void * arg0) {
    return func_00157990((char *)arg0 + 0x10);
}
