// range: 0x30F460 0x30F470
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_0030F470();

int func_0030F460(void * arg0) {
    return func_0030F470((char *)arg0 + 0x810);
}
