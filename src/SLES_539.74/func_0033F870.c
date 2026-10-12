// range: 0x33F870 0x33F880
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00131188();

int func_0033F870(void *arg0, void *arg1, void *arg2, void *arg3) {
    return func_00131188(arg0, 0, 40, arg3);
}
