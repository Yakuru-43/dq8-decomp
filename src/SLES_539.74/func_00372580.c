// range: 0x372580 0x372590
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_0025AB80();

int func_00372580(void * arg0) {
    return func_0025AB80(*(s16 *)((char *)arg0 + 0x2));
}
