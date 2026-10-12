// range: 0x298520 0x298530
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_002B0050();

int func_00298520(void * arg0) {
    return func_002B0050(*(s32 *)((char *)arg0 + 0x0));
}
