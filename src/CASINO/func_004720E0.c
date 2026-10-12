// range: 0x4720E0 0x4720F0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_1EA6C0();

int func_004720E0(void * arg0) {
    return func_1EA6C0((char *)arg0 + 0x1C8);
}
