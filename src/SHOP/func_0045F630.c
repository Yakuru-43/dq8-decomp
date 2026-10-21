// range: 0x45F630 0x45F640
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_24D380();

int func_0045F630(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_24D380(arg0, 1, arg1, arg3);
}
