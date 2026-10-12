// range: 0x4611C0 0x4611D0
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_1E73E0();

int func_004611C0(void * arg0) {
    return func_1E73E0((char *)arg0 + 0x1F0);
}
