// range: 0x3714F0 0x371500
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00371500();

int func_003714F0(void * arg0, void * arg1) {
    return func_00371500(arg0, (void *)0);
}
