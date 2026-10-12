// range: 0x16A420 0x16A430
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00131188();

int func_0016A420(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00131188(arg0, 0, 520, arg3);
}
