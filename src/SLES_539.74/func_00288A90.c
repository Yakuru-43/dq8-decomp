// range: 0x288A90 0x288AA0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_001E7470();

int func_00288A90(void * arg0) {
    return func_001E7470((char *)arg0 + 0x1F0);
}
