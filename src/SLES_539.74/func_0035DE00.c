// range: 0x35DE00 0x35DE10
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00358260();

int func_0035DE00(void * arg0) {
    return func_00358260(*(s32 *)((char *)arg0 + 0x0));
}
