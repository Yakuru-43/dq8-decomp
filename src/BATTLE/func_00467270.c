// range: 0x467270 0x467280
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_1EA6C0();

int func_00467270(void * arg0) {
    return func_1EA6C0((char *)arg0 + 0x1C8);
}
