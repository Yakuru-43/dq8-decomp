// range: 0x16A840 0x16A850
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_001EA6C0();

int func_0016A840(void * arg0) {
    return func_001EA6C0((char *)arg0 + 0x1C8);
}
