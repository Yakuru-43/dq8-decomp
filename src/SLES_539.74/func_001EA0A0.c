// range: 0x1EA0A0 0x1EA0B0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_001E76D0();

int func_001EA0A0(void * arg0) {
    return func_001E76D0((char *)arg0 + 0x1F0);
}
