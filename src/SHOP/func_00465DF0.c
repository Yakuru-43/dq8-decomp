// range: 0x465DF0 0x465E00
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_1EA6C0();

int func_00465DF0(void * arg0) {
    return func_1EA6C0((char *)arg0 + 0x1C8);
}
