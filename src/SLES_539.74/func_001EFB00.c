// range: 0x1EFB00 0x1EFB10
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_001EFB10();

int func_001EFB00(void * arg0) {
    return func_001EFB10((char *)arg0 + 0x70);
}
