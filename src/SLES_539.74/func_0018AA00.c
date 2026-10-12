// range: 0x18AA00 0x18AA10
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_0019AD70();

int func_0018AA00(void * arg0) {
    return func_0019AD70((char *)arg0 + 0x68E0);
}
