// range: 0x2223F0 0x222400
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_001FFB70();

int func_002223F0(void * arg0) {
    return func_001FFB70((char *)arg0 + 0x1F18);
}
