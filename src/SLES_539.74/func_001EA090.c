// range: 0x1EA090 0x1EA0A0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_001E7640();

int func_001EA090(void * arg0) {
    return func_001E7640((char *)arg0 + 0x1F0);
}
