// range: 0x207C10 0x207C20
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00131188();

int func_00207C10(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00131188(arg0, 0, 104, arg3);
}
