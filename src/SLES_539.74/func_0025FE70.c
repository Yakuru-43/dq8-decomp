// range: 0x25FE70 0x25FE80
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00131188();

int func_0025FE70(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00131188(arg0, 0, 976, arg3);
}
