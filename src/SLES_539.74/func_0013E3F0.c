// range: 0x13E3F0 0x13E400
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00157B30();

int func_0013E3F0(void * arg0) {
    return func_00157B30((char *)arg0 + 0x10);
}
