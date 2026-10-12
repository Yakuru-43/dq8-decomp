// range: 0x33F830 0x33F840
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00131188();

int func_0033F830(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00131188(arg0, 0, 40, arg3);
}
