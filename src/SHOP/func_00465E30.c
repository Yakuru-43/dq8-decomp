// range: 0x465E30 0x465E40
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_1EA6C0();

int func_00465E30(void * arg0) {
    return func_1EA6C0((char *)arg0 + 0x1C8);
}
