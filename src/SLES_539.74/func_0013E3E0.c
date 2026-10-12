// range: 0x13E3E0 0x13E3F0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00157AF0();

int func_0013E3E0(void * arg0) {
    return func_00157AF0((char *)arg0 + 0x10);
}
