// range: 0x13E400 0x13E410
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00157B70();

int func_0013E400(void * arg0) {
    return func_00157B70((char *)arg0 + 0x10);
}
