// range: 0x345E00 0x345E10
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00131188();

int func_00345E00(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00131188(arg0, 0, 320, arg3);
}
