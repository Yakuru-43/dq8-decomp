// range: 0x288A70 0x288A80
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_001E77F0();

int func_00288A70(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_001E77F0((char *) (arg0) + 0x1F0, -1, arg1, arg3);
}
