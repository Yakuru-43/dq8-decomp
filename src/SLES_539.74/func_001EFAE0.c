// range: 0x1EFAE0 0x1EFAF0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_001EC000();

int func_001EFAE0(void * arg0) {
    return func_001EC000((char *)arg0 + 0x70);
}
